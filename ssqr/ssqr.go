package main

import (
	"encoding/json"
	"errors"
	"fmt"
	"time"
	"os"
	"github.com/rumblefrog/go-a2s"
	"github.com/xv-chang/rconGo/core"
)

type Action string

const (
	Rcon	Action = "rcon"
	Query	Action = "query"
)

var (
	ErrGlobal = errors.New("error")
	ErrNotAuth = errors.New("error_password")
)

type InformationServer struct {
	Map			string `json:"map"`
	Players		int	`json:"players"`
	MaxPlayers	int	`json:"max_players"`
	Password	bool   `json:"password"`
}

func main() {
	args := os.Args

	if len(args) < 3 {
		fmt.Println(ErrGlobal)
		return
	}

	action := Action(args[1])
	if action == Rcon && len(args) < 5 {
		fmt.Println(ErrGlobal)
		return
	}

	ip := args[2]
	port := args[3]

	if action == Rcon {
		command := args[4]
		password := args[5]
		result, errResult := handleRcon(ip, port, command, password)

		if errResult != nil {
			fmt.Println(errResult)
			return
		}

		fmt.Println(result)
	}

	if action == Query {
		result, errResult := handleQuery(ip, port)

		if result == nil {
			fmt.Println(ErrGlobal)
			return
		}

		if errResult != nil {
			fmt.Println(ErrGlobal)
			return
		}

		body, err := json.Marshal(result)
		if err != nil {
			fmt.Println(ErrGlobal)
			return
		}

		fmt.Println(string(body))
	}
}

func handleRcon(ip, port, command, password string) (string, error) {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(ErrGlobal)
			os.Exit(1) // костыль
		}
	}()

	host := fmt.Sprintf("%s:%s", ip, port)
	client := core.NewRCONClient(host, password)
	defer client.Close()

	errAuth := client.SendAuth()
	if errAuth != nil {
		return "", ErrNotAuth
	}

	result, errQuery := client.ExecCommand(command)
	if errQuery != nil {
		return "", ErrGlobal
	}

	return result, nil
}

func handleQuery(ip, port string) (*InformationServer, error) {
	host := fmt.Sprintf("%s:%s", ip, port)
	client, err := a2s.NewClient(
		host,
		a2s.TimeoutOption(time.Second * 2),
	)
	if err != nil {
		return nil, err
	}
	defer client.Close()
	
	result, err := client.QueryInfo()
	if err != nil {
		return nil, err
	}

	return &InformationServer{
		Map:		result.Map,
		Players:	int(result.Players),
		MaxPlayers:	int(result.MaxPlayers),
		Password:	result.Visibility,
	}, nil
}

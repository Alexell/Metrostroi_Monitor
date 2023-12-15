package main

import (
	"encoding/json"
	"errors"
	"fmt"
	"os"
	"github.com/xv-chang/rconGo/core"
)

type Action string

const (
	Rcon  Action = "rcon"
	Query Action = "query"
)

var (
	ErrNotAuth = errors.New("error_password")
)

type InformationServer struct {
	Map        string `json:"map"`
	Players    int    `json:"players"`
	MaxPlayers int    `json:"max_players"`
	Password   bool   `json:"password"`
}

func main() {
	args := os.Args

	if len(args) < 3 {
		fmt.Println("error")
		return
	}

	action := Action(args[1])
	if action == Rcon && len(args) < 5 {
		fmt.Println("error")
		return
	}

	ip := args[2]
	port := args[3]

	command := ""
	password := ""
	if action == Rcon {
		command = args[4]
		password = args[5]
	}

	if action == Rcon {
		result, errResult := handleRcon(ip, port, command, password)

		if errResult != nil {
			if errors.As(errResult, &ErrNotAuth) {
				fmt.Println(errResult.Error())
				return
			}

			fmt.Println("error")
			return
		}

		fmt.Println(result)
	}

	if action == Query {
		result, errResult := handleQuery(ip, port)

		if result == nil {
			fmt.Println("error")
			return
		}

		if errResult != nil {
			fmt.Println("error")
			return
		}

		body, err := json.Marshal(result)
		if err != nil {
			fmt.Println("error")
			return
		}

		fmt.Println(string(body))
	}
}

func handleRcon(ip, port, command, password string) (string, error) {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("error")
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
		return "", errQuery
	}

	return result, nil
}

func handleQuery(ip, port string) (*InformationServer, error) {
	host := fmt.Sprintf("%s:%s", ip, port)
	client := core.NewServerQuery(host)
	defer client.Close()
	result := client.GetInfo()

	return &InformationServer{
		Map:        result.Map,
		Players:    int(result.Players),
		MaxPlayers: int(result.MaxPlayers),
		Password:   result.Visibility != 0,
	}, nil
}

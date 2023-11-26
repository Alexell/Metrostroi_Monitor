import sys
import json
from a2squery import A2SQuery
from rcon.source import Client

action = str(sys.argv[1])
ip = str(sys.argv[2])
port = int(sys.argv[3])

if action == 'query':
	try:
		with A2SQuery(ip, port) as a2s:
			data = a2s.info()
			result = {}
			result['name'] = data.name
			result['map'] = data.map
			result['players'] = data.players
			result['max_players'] = data.max_players
			result['password'] = data.password
			result = json.dumps(result)
			print(result)
	except:
		print('error')
elif action == 'rcon':
		command = str(sys.argv[4])
		password = str(sys.argv[5])
		try:
			with Client(ip, port, passwd=password) as client:
				response = client.run(command)
		except:
			print('error')
else:
	print('error')
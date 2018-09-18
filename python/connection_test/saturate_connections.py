#!/usr/bin/env python

import socket
from time import sleep

address = "10.30.30.138"
port = 8080
socket_list = []

for i in range(0,1):
    socket_list.append( socket.create_connection( ( address, port ) ) )
    #sock.send("hello\n")


sleep(80)


for sock in socket_list:
    sock.close()

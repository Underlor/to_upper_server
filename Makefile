all:
	g++ -std=c++11 -Wall src/Socket.cpp src/SocketClient.cpp src/ListenerSocket.cpp src/main.cpp -o EasyServer
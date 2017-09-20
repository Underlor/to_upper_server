#pragma once
#include "Socket.h"

class SocketClient : public Socket
{
public:
	sockaddr addr;

	SocketClient(int, sockaddr);

	ssize_t Send(byte*, size_t);
	ssize_t Read(byte*, size_t);

	char* GetAddrStr();
};

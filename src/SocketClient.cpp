#include "SocketClient.h"

#include <arpa/inet.h>

void *get_in_addr(sockaddr *sa);

SocketClient::SocketClient(int descriptor, sockaddr addr) : addr(addr)
{
	this->descriptor = descriptor;
}

ssize_t SocketClient::Send(byte* buffer, size_t length)
{
	return send(this->descriptor, buffer, length, 0);
}

ssize_t SocketClient::Read(byte* buffer, size_t length)
{
	return recv(this->descriptor, buffer, length, 0);
}

char* SocketClient::GetAddrStr()
{
	return inet_ntoa(*(in_addr*)get_in_addr(&addr));
}

void *get_in_addr(sockaddr *sa)
{
	return sa->sa_family == AF_INET
		? (void *) &((sockaddr_in*)sa)->sin_addr
		: (void *) &((sockaddr_in6*)sa)->sin6_addr;
}
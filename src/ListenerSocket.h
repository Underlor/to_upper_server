#pragma once

#include "SocketClient.h"
#include "Socket.h"


class ListenerSocket : public Socket
{
public:
	/**
	* \brief Socket Server port
	*/
	int port;

	ListenerSocket(int);

	void Listen() const;
	SocketClient* Accept() const;
};

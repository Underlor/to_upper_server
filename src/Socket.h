#pragma once

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>

typedef unsigned char byte;

class Socket
{
protected:
	int descriptor;
public:
	void Close();
};

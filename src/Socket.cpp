#include "Socket.h"

void Socket::Close()
{
	close(this->descriptor);
}

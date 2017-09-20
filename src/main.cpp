#include <cstdio>
#include "Socket.h"
#include <iostream>
#include "ListenerSocket.h"
#include <fstream>
#include <sstream>
#include <ctime>

#define PORT 8081

char* formatedTime()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char* temp = new char[20];
	strftime(temp, 20, "[%H:%M:%S] ", ltm);
	return temp;
}

int main()
{
	std::ofstream log;
	log.open("easyserver.log", std::ios::app);
	if (!log.is_open()) 
	{
		std::cout << "Can't create or open log file!" << std::endl;
		return 1;
	}

	log << formatedTime() << "Server started!" << std::endl;

	ListenerSocket* listener = new ListenerSocket(PORT);
	listener->Listen();

	log << formatedTime() << "Listener started!" << std::endl;

	while (true)
	{
		SocketClient* client = listener->Accept();

		log << formatedTime() << "Client connected from: " << client->GetAddrStr() << "!" << std::endl;

		std::stringstream stream;

		byte buffer[1024];

		int bytesReaded;
		unsigned long long length = 0;

		while((bytesReaded = client->Read(buffer, sizeof buffer)) > 0)
		{
			for (int i = 0; i < bytesReaded; i++)
				stream << (byte)toupper(buffer[i]);

			length += bytesReaded;

			log << formatedTime() << "Server received " << bytesReaded << " bytes from: " << client->GetAddrStr() << "!" << std::endl;

			if(buffer[bytesReaded-1] == 0)
				break;
		}
		
		client->Send((byte*)stream.str().c_str(), length);
		
		log << formatedTime() << "Server send " << bytesReaded << " bytes to: " << client->GetAddrStr() << "!" << std::endl;

		client->Close();

		log << formatedTime() << "Client disconnected from: " << client->GetAddrStr() << "!" << std::endl;
	}
}

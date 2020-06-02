#include <iostream>
#include <string>
#include <signal.h>

#include <glog/logging.h>

#include "TCPClient.h"


TCPClient tcp;

void sig_exit(int s)
{
	tcp.exit();
	exit(0);
}

int main(int argc, char *argv[])
{
	if(argc != 4) {
		cerr << "Usage: ./client ip port message" << endl;
		return 0;
	}
	signal(SIGINT, sig_exit);

	tcp.setup(argv[1],atoi(argv[2]));
	int i = 0;
	while(1)
	{
        const std::string string2Send(argv[3] + std::to_string(++i));
        LOG(INFO) << "Send: " << string2Send;
		tcp.Send(string2Send);
		string rec = tcp.receive();
		if( rec != "" )
		{
			cout << rec << endl;
		}
		sleep(1);
	}
	return 0;
}

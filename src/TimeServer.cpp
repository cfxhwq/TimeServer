//============================================================================
// Name        : TimeServer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

#define MAXFD 64
#define MAXLINE 255

void daemon_init(const char *pname, int facility) {
	int i;
	pid_t pid;
	if ((pid = fork()) != 0) {
		exit(0);
	}

	setsid();
	signal(SIGHUP, SIG_IGN);
	if ((pid = fork()) != 0) {
		exit(0);
	}

	chdir("/");
	umask(0);

	for (i = 0; i < MAXFD; ++i) {
		close(i);
		openlog(pname,LOG_PID,facility);
	}
}

int main() {
	cout << "" << endl; // prints 
	return 0;
}

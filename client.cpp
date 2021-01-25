// Client side C/C++ program to demonstrate Socket programming 
#include <iostream>
#include <string>

#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

int main() 
{ 
	// std::cout << "Hello this is the client app " << std::endl;


	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	// char *hello = "Hello from client"; 
	char *hello = "Hello from th client";
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
	send(sock , hello , strlen(hello) , 0 ); 
	// printf("Hello message sent\n"); 
	std::cout << "Hello message sent" << std::endl;
	valread = read( sock , buffer, 1024); 
	// printf("%s\n",buffer ); 
	std::cout << buffer << std::endl;
	return 0; 
} 

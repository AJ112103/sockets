//Based on IPv4
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){

    int socketFD = socket(AF_INET, SOCK_STREAM, 0); //socket file descriptor is returned because the socket has been implemented as a file in the system so we read and write from it
    char* ip = "172.217.194.102";
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(80);   //htons: converts port number to network byte order which is always big endian // 80: destination port for client, server should be listening on port 80. 
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);   //pton = presentation to network


    int result = connect(socketFD, (struct sockaddr*)&address, sizeof address);

    if(result ==  0){
       printf("connection was successful\n");
    }

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socketFD, message, strlen(message), 0);

    char buffer[1024];
    recv(socketFD, buffer, 1024, 0);

    printf("Response was %s\n", buffer);
    
    return 0;
}
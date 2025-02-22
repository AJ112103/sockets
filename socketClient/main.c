#include "../socketUtil/socketutil.h"

int main(){

    int socketFD = createTCPIpv4Socket(); //socket file descriptor is returned because the socket has been implemented as a file in the system so we read and write from it
    struct sockaddr_in *address = createIPv4Address("142.251.10.93", 80);

    int result = connect(socketFD, (struct sockaddr*)address, sizeof(*address));

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


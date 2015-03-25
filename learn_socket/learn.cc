
#include <stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h> //inet_addr
#include <unistd.h>

/*
// IPv4 AF_INET sockets:
struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET, AF_INET6
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};
 
struct in_addr {
    unsigned long s_addr;          // load with inet_pton()
    // nothing but a long ip address
};
 
struct sockaddr {
    unsigned short    sa_family;    // address family, AF_xxx
    char              sa_data[14];  // 14 bytes of protocol address
};
*/
 
int main(int argc , char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message , server_reply[2000];
    
    //printf("see what happened"); 
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
         
    server.sin_addr.s_addr = inet_addr("173.194.127.82");
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );
 	
    //Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
    
    puts("Connected\n");
     
    //Send some data
    message = "GET / HTTP/1.1\r\n\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");
     
    //Receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts("Reply received\n");
    puts(server_reply);
    close(socket_desc);

    return 0;
}
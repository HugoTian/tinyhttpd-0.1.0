#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
 int sockfd;
 int len;
 struct sockaddr_in address;
 int result;
 char ch[2000] ;
 char message[256];

 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 address.sin_family = AF_INET;
 address.sin_addr.s_addr = inet_addr("127.0.0.1");
 address.sin_port = htons(8889);
 len = sizeof(address);
 result = connect(sockfd, (struct sockaddr *)&address, len);

 if (result == -1)
 {
  perror("oops: client1");
   return 1;
 }
 //printf("please input some message\n");
 //read and display
 read(sockfd, ch, 2000);
 ch[500] = '\0';
 printf("char from server = %s\n", ch);

 //write and send
 scanf("%s",message);
 message[255] = '\0';
 write(sockfd, message, strlen(message));

 //read and display
 read(sockfd, ch, 2000);
 ch[500] = '\0';
 printf("char from server = %s\n", ch);

 //write and send
 scanf("%s",message);
 message[255] = '\0';
 write(sockfd, message, strlen(message));

 read(sockfd, ch, 2000);
 ch[500] = '\0';
 printf("char from server = %s\n", ch);

 

 close(sockfd);
 return 1;
}

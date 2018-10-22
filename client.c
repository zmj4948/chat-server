#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>


int main(){
        struct sockaddr_in serv;
        int fd;
        int conn;
        char message[100]="";
	
	fd=socket(AF_INET, SOCK_STREAM, 0);
	serv.sin_family=AF_INET;
	serv.sin_port= htons(8096);
	
	inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr); 
	connect(fd, (struct sockaddr *)&serv, sizeof(serv)); 
	while(1) {
    		printf("Enter a message: ");
    		fgets(message, 100, stdin);
    		send(fd, message, strlen(message), 0);
    	}

}

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socketvar.h>
#include <unistd.h>

#define MAXLINE 4096


int main()
{

    struct sockaddr_in myadd;
    int i = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    char buff[4096];
    myadd.sin_family = AF_INET;
    myadd.sin_addr.s_addr = htonl(INADDR_ANY);
    myadd.sin_port = 8000;

    bind(i,(struct sockaddr*)&myadd,sizeof(myadd));

    listen(i,100);

    int connect_fd;

    while(1){

       connect_fd = accept(i,(struct sockaddr*)NULL,NULL);
        printf("%d",connect_fd);
       if(connect_fd > 0){
        if(!fork()){
            while(1){
            int n = recv(connect_fd,buff,MAXLINE,0);
            printf("%s",buff);
            printf("111111111111111111");

            }

        }

       }

    }




    printf("%d",i);
    printf("Hello world!\n");
    return 0;
}

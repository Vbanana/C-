#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <Winsock2.h>
#include <pthread.h>
#include <time.h>
void* child();
char buf[3000];
int sockfd = 0;
int port2,x=0;
char ip2[20];
struct sockaddr_in info;
int main()
{
	char ip[20];
	int port;
	printf("by 蕉蕉 https://www.youtube.com/channel/UCPczJ9COLuFZOoSlvZW7cFw?view_as=subscriber\n");
	printf("你要傳送的訊息\n");
	gets(ip);
	printf("ip=");
	scanf("%s",ip);
	printf("port=");
	scanf("%d",&port);
	
	strcpy(ip2,ip);
	port2=port;
	WORD wVersionRequested = MAKEWORD(2,2); 
    WSADATA wsaData;
    
    if(WSAStartup(wVersionRequested,&wsaData)!= 0)
    {
        printf("初始化WinSock失敗\n");
        return 0;
    }
    
    int sockfd = 0;
    sockfd = socket(AF_INET ,SOCK_STREAM , 0);

    if (sockfd == -1){
        printf("Fail to create a socket.");
    }

    struct sockaddr_in info;
    memset(&info,0,sizeof(info));
    info.sin_family = PF_INET;
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = htons(port);
    
    int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
    if(err==-1){
        printf("Connection error");
        return 0;
    }
    
    
	int i,b;
    
    while(1)
    {
    	i=0;
		do
		{
			x++;
			b=send(sockfd,buf,sizeof(buf),0);
			printf("%d success %d size\n",x,b);
			if(b==-1)
			{
				pthread_t a; // 宣告 pthread 變數
	    		pthread_create(&a, NULL, child,NULL); // 建立子執行緒
	    		pthread_join(a, NULL);
			}
			
		}
		while(b!=-1);
		WORD wVersionRequested = MAKEWORD(2,2); 
	    WSADATA wsaData;
	    
	    if(WSAStartup(wVersionRequested,&wsaData)!= 0)
	    {
	        printf("初始化WinSock失敗\n");
	        return 0;
	    }
	    
	    int sockfd = 0;
	    sockfd = socket(AF_INET , SOCK_STREAM , 0);
	
	    if (sockfd == -1){
	        printf("Fail to create a socket.");
	    }
	
	    struct sockaddr_in info;
	    memset(&info,0,sizeof(info));
	    info.sin_family = PF_INET;
	    info.sin_addr.s_addr = inet_addr(ip);
	    info.sin_port = htons(port);
	    
	    int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
	    if(err==-1){
	        printf("Connection error");
	        return 0;
	    }
	}
		
		
}

void* child()
{
	int i;
	WORD wVersionRequested = MAKEWORD(2,2); 
    WSADATA wsaData;
    
		    if(WSAStartup(wVersionRequested,&wsaData)!= 0)
		    {
		        printf("初始化WinSock失敗\n");
		        return 0;
		    }
			
		    int sockfd = 0;
		    sockfd = socket(AF_INET , SOCK_STREAM , 0);
		
		    if (sockfd == -1){
		        printf("Fail to create a socket.");
		    }
		
		    struct sockaddr_in info;
		    memset(&info,0,sizeof(info));
		    info.sin_family = PF_INET;
		    info.sin_addr.s_addr = inet_addr(ip2);
		    info.sin_port = htons(port2);
			int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
	    	if(err==-1){
		        printf("Connection error");
		        return 0;
    		}
    		int b,a=0;
	while(1)
	{
		x++;
		b=send(sockfd,buf,sizeof(buf),0);
		printf("%d success %d size\n",x,b);
		if(b==-1)
		{
			break;
		}
	}
} 

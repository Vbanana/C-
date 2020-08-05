#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	FILE *file = fopen("Record.log", "a");
    //初始化WSA
    WORD sockVersion = MAKEWORD(2,2);
    WSADATA wsaData;
    if(WSAStartup(sockVersion, &wsaData)!=0)
    {
        return 0;
    }

    //?建套接字
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }

    //?定IP和端口
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = INADDR_ANY; 
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("bind error !");
    }

    //?始?听
    if(listen(slisten, 5) == SOCKET_ERROR)
    {
        printf("listen error !");
        return 0;
    }

    //循?接收?据
    SOCKET sClient;
    struct sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    char revData[1024]; 
    
        printf("等待連接...\n");
        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
        if(sClient == INVALID_SOCKET)
        {
            printf("accept error !");
            //continue;
        }
        printf("接受到一個連接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
    while (1)
    {
        //接收?据
        int ret = recv(sClient, revData, sizeof(revData), 0);
		if(ret > 0)
		{
	        revData[ret]= 0x00;
	   	//	printf("%ls",revData);
	        file=fopen("Record.log", "a");
		    fprintf(file, "%ls", revData);
		    fclose(file);
		}
        
    }
    closesocket(slisten);
    WSACleanup();
    return 0;
}            

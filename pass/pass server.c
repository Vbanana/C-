#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	FILE *file = fopen("Record.log", "a");
    //��l��WSA
    WORD sockVersion = MAKEWORD(2,2);
    WSADATA wsaData;
    if(WSAStartup(sockVersion, &wsaData)!=0)
    {
        return 0;
    }

    //?�خM���r
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }

    //?�wIP�M�ݤf
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = INADDR_ANY; 
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("bind error !");
    }

    //?�l?�v
    if(listen(slisten, 5) == SOCKET_ERROR)
    {
        printf("listen error !");
        return 0;
    }

    //�`?����?�u
    SOCKET sClient;
    struct sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    char revData[1024]; 
    
        printf("���ݳs��...\n");
        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
        if(sClient == INVALID_SOCKET)
        {
            printf("accept error !");
            //continue;
        }
        printf("������@�ӳs���G%s \r\n", inet_ntoa(remoteAddr.sin_addr));
    while (1)
    {
        //����?�u
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

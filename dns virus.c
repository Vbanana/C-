#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <sys/stat.h>
#define max 150
void main()
{
	wchar_t myString1[16] = { 0x8549, 0x8549};
	wchar_t myString2[16] = { 0x5275,0x4F5C,0x8005};
	wchar_t myString3[16] = { 0x8336};
	wchar_t myString4[16] = { 0x4FEE,0x6539};
	setlocale(LC_ALL, "");
	wprintf(L"%ls by BT%ls\n%ls by %ls\n",myString2,myString3,myString4,myString1);
	int i,h=open("C:\\WINDOWS\\system32\\drivers\\etc\\hosts",O_WRONLY|O_APPEND);
	char a[9]={"0.0.0.0 "},url[max],n='\n';
	if(h!=-1)
	while(1)
	{
		printf("input url:");
		scanf("%s",url);
		if(url=="quit")
		  break;
		write(h,a,8);
		write(h,url,strlen(url));
		write(h,&n,1);
		fflush(stdin);
	}	
	close(h);
	system("pause");
} 

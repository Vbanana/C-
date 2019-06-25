#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#define max 150
int main()
{
	printf("創作者by BT茶\n修改 by 蕉蕉\n");
	int h=open("C:\\WINDOWS\\system32\\drivers\\etc\\hosts",O_CREAT|O_WRONLY|O_APPEND);
	char a[9]={"0.0.0.0 "},url[max],n='\n';
	write(h,&n,1);
	if(h!=-1)
		while(1)
		{
			fflush(stdin);
			printf("input url:");
			scanf("%s",url);
			if(url=="quit")
			  break;
			write(h,a,8);
			write(h,url,strlen(url));
			write(h,&n,1);
		}	
	close(h);
	system("pause");
	return 0;
} 

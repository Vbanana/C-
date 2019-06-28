#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
void main()
{
	time_t t;
    srand((unsigned) time(&t));
	int ran,i,j;
	char a[10],b;
    while(1)    //you can change j=0;j<20
	{
		Sleep(30); 
		char point[30]={"D:\\"};
		for(i=0;i<4;i++) //you can change i=0;i<4
		{
			ran=rand()%1000; //you can change 1000
			itoa(ran,a,10);
			strcat(point,a);
		}
		int Fil=open(point,O_CREAT|O_WRONLY|O_APPEND);
		ran=rand()%555;    //you can change 555
		if(Fil!=-1)
		{
			write(Fil,&ran,3);
		}
	}
}

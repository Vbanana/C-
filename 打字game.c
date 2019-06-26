#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
	int max,ran[60],i,b,c;
	double miss; 
	char a[100];
	time_t t;
	srand((unsigned) time(&t));
	while(1)
	{
		clock_t t1, t2;
		c=miss=0;
		do
		  max=rand()%60;
		while(max<29);
		
		for(i=0;i<max;i++)
		{
			do
			  ran[i]=rand()%123;
			while(ran[i]<97);
		}
		for(i=0;i<max;i++)
		{
		  printf("%c",ran[i]);
		}
		printf("\n");
		t1=clock();
		scanf("%s",a);
		t2 = clock();
		for(i=0;i<max;i++)
		{
			b=a[i];
			if(b!=ran[i])
			{ 
			  printf("_");
			  miss++;
			} 
			else
			  printf("%c",ran[i]);
		}
		
		printf("\n");
		miss=miss/max*100;
		printf("%lfs ", (t2-t1)/(double)(CLOCKS_PER_SEC));
		printf("%lf%%¿ù»~\n\n",miss);
	}
}

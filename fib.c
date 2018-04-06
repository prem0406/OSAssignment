#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>



void *fib(void *p);
int main()
{
	pthread_t thread;
	//int arr*;
	printf("\nEnter a no: ");
	int n;
	scanf("%d",&n);
	//arr=(int*)malloc(n*sizeof(int));
	pthread_create(&thread,NULL,fib,(void*)(intptr_t)n);
	pthread_join(thread,NULL);
	printf("\nFibbonacci Series: ");
	/*for(int i=0;i<n;i++)
	{
		printf("%d  ",*(arr+i));
	}*/
		
}

void *fib(void *p)
{	
	int n=(intptr_t)p;
	int i=0;
	int j=1;
	int temp;
	printf("\nThis is Fib: ");
	printf("%d  ",i);
	printf("%d  ",j);
	for(int k=0;k<n-2;k++)
	{
		temp=j+i;
		i=j;
		j=temp;
		printf("%d  ",temp);
	}
}

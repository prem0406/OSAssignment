#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int *arr;

void *fib(void *len);
int main()
{
	pthread_t t;
	printf("\nEnter a no: ");
	int n;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	pthread_create(&t,NULL,fib,(void*)(intptr_t)n);
	pthread_join(t,NULL);
	printf("\nFibbonacci Series: ");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",*(arr+i));
	}
		
}

void *fib(void *len)
{	
	int n=(intptr_t)len;
	int i=0;
	int j=1;
	int temp;
	*arr=i;
	*(arr+1)=j;
	for(int k=2;k<n;k++)
	{
		temp=j+i;
		i=j;
		j=temp;
		*(arr+k)=temp;
	}
}

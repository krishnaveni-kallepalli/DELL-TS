//reverse array without taking 
#include<stdio.h>
#define N 5
void rev(int *a)
{
	
	int i,temp;
	for(i=0;i<N/2;i++)
	{
		temp=*(a+i);
		a[i]=a[N-i-1;
		a[N-i-1]=temp;
	}
}
int main()
{
	int a[N],i;
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	rev(a);
	printf("After reversing:\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",a[i]);
	}
}

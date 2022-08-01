#include<stdio.h>
#define n 5
void rev(int *arr[])
{
	int i,temp;
	for(i=0;i<n/2;i++)
	{
	    temp=*arr[i];
	    *arr[i]=*arr[n-i-1];
	    *arr[n-i-1]=temp;
	}
    	for(i=0;i<n;i++)
    	    printf("%d\t",*arr[i]);
}

int main()
{
	int arr[n],i,temp;
	int *p;
	p=arr;
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	}
	rev(arr);
}

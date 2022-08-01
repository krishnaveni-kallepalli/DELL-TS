//frequncy of each eleement in an array

#include<stdio.h>
#define n 10
void freq(int *arr[n],int *a[n])
{
	int i,j,count;
	for(i=0;i<n;i++)
	{
		count =1;
		for(j=i+1;j<n;j++)
		{
			if(*arr[i]==*arr[j])
			{
				count++;
				a[j]=0;
			}
		}
		if(a[j]!=0)
		{
			a[i]=count;
		}
		printf("frequency of elements:\n");
		for(i=0;i<n;i++)
		{
			printf("frequency is %d:%d",*arr[i],*a[i]);
		}
		
	}
}
int main()
{
	int arr[n],a[n];
	int i,j;
	void (*fp)(int arr[n],int a[n])=freq;
	
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	fp(arr,a);
}



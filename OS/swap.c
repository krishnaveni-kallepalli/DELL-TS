#include<stdio.h>
#include<pthread.h>


typedef struct node
{
	int a;
	int b;
}S;


void* swap_ptr(S *stu)
{
	int temp;
	temp=stu->a;
	stu->a=stu->b;
	stu->b=temp;
}


int main()
{
	S *ptr;
	printf("Enter a = ");
	scanf("%d",&ptr->a);

	printf("Enter b = ");
	scanf("%d",&ptr->b);

	pthread_t newthread;
	pthread_create(&newthread,NULL,&swap_ptr,ptr);
	pthread_join(newthread,NULL);
	printf("After swapping = %d %d\n",ptr->a,ptr->b);
	return 0;
}


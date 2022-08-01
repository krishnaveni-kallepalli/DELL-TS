#include"header.h"
//libraries for thread handling
//structure of database

int count=3;

void view()
{
pthread_t tid[3];
pthread_create(&tid[0],NULL,p1,0);
pthread_create(&tid[1],NULL,p2,0);
pthread_create(&tid[2],NULL,p3,0);
pthread_join(tid[0],NULL);
pthread_join(tid[1],NULL);
pthread_join(tid[2],NULL);
//free(head);
}


void database_search(char id[])
{
	short f=0;//set to 1 when id is found

	employee_data *temp=NULL;
	employee_data *new=head;
	printf("id is %s\n",id);
	while((new->link)!=NULL)
	{
		if((strcmp(new->EMP_ID,id))==0)
		{
			//printf("id already exist:\n");
		
			printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);

			return ;
		}
		new=new->link;
	}

}
void *p1(void *p)
{
	pthread_mutex_lock(&lock);
	details();
	pthread_mutex_unlock(&lock);
}
void *p2(void *p)
{
pthread_mutex_lock(&lock);
puts(id0);
puts(id1);
if(strcmp(id0,id1)==0)
	printf("details already filled\n");
else
details();
pthread_mutex_unlock(&lock);
}
void *p3(void *p)
{
pthread_mutex_lock(&lock);
if(strcmp(id1,id2)==0)
	printf("details already filled\n");
else
details();
pthread_mutex_unlock(&lock);
}
void details()
{
	int flag=0;
        char id[10];
        printf("\nenter empid 1\n");
        scanf("%s",id);

//        printf("%d\n",count);
        if(count==3)
        {
                strcpy(id0,id);
                database_search(id0);

                count--;
        }

        else if(count==2)
        {
        strcpy(id1,id);
        if((strcmp(id0,id1))==0)
        {
                printf("already printed :\n");
                return ;
        }
        else
        database_search(id1);

        count--;
        }
        else
        {
                strcpy(id2,id);
        }
        if(count == 1)
        {
                if(((strcmp(id0,id2))==0)||(((strcmp(id1,id2))==0)))
                {
                printf("already printed :\n");
                return ;
                }
        else
        database_search(id2);
        }
}


#include"header.h"
//#include"TSIndia_Emp_DB.h"
//void Display(employee_data **);//display function for local data base
employee_data *head=NULL,*temp=NULL;

void ready_database()
{

	char ch;
	char test_data[50];//char buffer for temporarily store the data
	int i=0,flag=0,k=0;
/********** Linked list variables ***********/
	employee_data *new=NULL;
//	employee_data *head=NULL;
//	employee_data *temp=NULL;

	FILE *fp;			//file pointer
	fp=fopen("TSIndia_Emp_DB.xlsx","r");//open xl file in read mode
	if(fp==NULL)
	{
		printf("File cannot opened Successfully\n");
	}
	else
	{
		while((ch=getc(fp))!=EOF)//reading the xl file data byte by byte till end of file
		{
			test_data[i++]=ch;		//storing the data in a char buffer
			new=(employee_data *)malloc(sizeof(employee_data));// dynamic memory allocate for structure
			while((ch=getc(fp))!='\n')//reading the data till new line
			{
				if((ch==','))//checking the comma for seperaing the data
				{
					i=0;
					flag++;
					if(flag==1)//Emp_ID seperation condition
					{
						strcpy(new->EMP_ID,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==2)//Name seperation condition
					{
						strcpy(new->Name,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==3)//GENDER seperation condition
					{
						new->GENDER=test_data[0];//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==4)//EMAIL_ID seperation condition
					{
						strcpy(new->EMAIL_ID,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==5)//Band seperation condition
					{
						strcpy(new->Band,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==6)//DOJ seperation condition
					{
						strcpy(new->DOJ,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==7)//Contact_No seperation condition
					{
						strcpy(new->Contact_No,test_data);//copy the buffer data to struct
						test_data[26]='\0';
						test_data[27]='\0';
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==8)//Reporting_Manager seperation condition
					{
						strcpy(new->Reporting_Manager,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==9)//Tech_area seperation condition
					{
						strcpy(new->Tech_area,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==10)//Project_info seperation condition
					{
						strcpy(new->Project_info,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
					}
					if(flag==11)//Status seperation condition
					{
						strcpy(new->Status,test_data);//copy the buffer data to struct
						memset(test_data,'\0',sizeof(test_data));//clear the buffer
								flag=0;
					}
				}
				else
				{
					test_data[i++]=ch;//storing the data in buffer
				}
					
			}
			new->link=NULL;//initialize the NULL to new link

			if(head==NULL)//check if head id NULL
			{
				head=temp=new;
			}
			else
			{
				temp->link=new;//linking the node
				temp=new;
			}


		}
	}
//	Display(&head);
//	free(new);	

	fclose(fp);
}
/*
void Display(employee_data **head)
{
	employee_data *new=(*head);
	int count=0;
	if(new==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(new!=NULL)
		{
			printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
			new=new->link;
			count++;
		}
		printf("count:%d\n",count);
	}
}*/
void xl_database_modify(employee_data **head1)//function for modify the data from the xl file
{
	FILE *fp;//decleare the file pointer
	char ch,buf[180];//decleare the char arr
	int i=0,flag=0;//decleare the i and flag wit zero
	employee_data *new=(*head1);//initilize the new to head
	fp = fopen("TSIndia_Emp_DB.xlsx","r+");//open  xl file in read and write mode
        if(fp == NULL)//checking the file is open or not
	{
                printf("file can not be open for some resion :\n");
                return ;
        }

        while ((ch=getc(fp))!=EOF)//read the data byte by byte from the xl file
        {
        if(ch=='\n')//checking new line
                i=0;
                buf[i++]=ch;//storing the data in char array
                if(flag==1)//checking the flag
                {
		//		printf("count before xl %d\n",r++);
                              fseek(fp, -1, SEEK_CUR);//set the file pointer current position to previous position
			      fprintf(fp,",%s,%c,%s,%s,%s,%s,%s,%s,%s,%s,",new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);//writing the data in the xl file after finding the id

			      	flag=0;//assign zero to flag
				memset(buf,'\0',sizeof(buf));//clear the buffer
                 }
                

        if(strstr(buf,new->EMP_ID))//searching the emp_id from the char buffer
                flag=1;//enable the flag

        if(i==179)//checking the i value and initilize with zero for avoiding the buffer over flow and segmentation fault
        i=0;
	}
	fclose(fp);//closing the file
}

void xl_delete_data(employee_data *status_regin)//function for changing the Employee Status from the xl sheet
{
	FILE *fp;//decleare the file pointer
        char ch,buf[180];//decleare the char arr
        int i=0,flag=0;//decleare the i and flag wit zero
   
        fp = fopen("TSIndia_Emp_DB.xlsx","r+");//open  xl file in read mode
        if(fp == NULL)//checking the file is open or not
	{
                printf("file can not be open for some resion :\n");
                return ;
        }

        while ((ch=getc(fp))!=EOF)//read the data byte by byte from the xl file
        {
        if(ch=='\n')//checking the new line in xl sheet
                i=0;
                buf[i++]=ch;//storing the data in char array
                if(flag==1)
                {		
				while((ch=getc(fp))!=EOF)//read the data byte byte from the xl file
				{
					if(ch==',')//checking the ',' in the xl file
						flag++;//increamenting the flag 
					if(flag==10)//chaecking the flag value
					{
                //              printf("count before xl %d\n",r++);
                             	 fseek(fp, -1, SEEK_CUR);//set the file pointer position current to previoue
                              	fprintf(fp,",%s,",status_regin->Status);//writing the data in status section in xl sheet

                                flag=0;
				return ;
					}
                                memset(buf,'\0',sizeof(buf));//clear the buffer
				}
		}
		if(strstr(buf,status_regin->EMP_ID))//searching the id from the char array
                flag=1;//enable the flag

        if(i==179)//checking the i value and initilize with zero for avoiding the buffer over flow and segmentation fault
        i=0;
        }
        fclose(fp);//close the file
}
void xl_database_add(employee_data **head1)//function for adding the data in the xl file
{
        FILE *fp;//decleare the file pointer
        employee_data *new=(*head1);//assign the head1 to temp 
        fp = fopen("TSIndia_Emp_DB.xlsx","a+");//open  xl file in read mode
        if(fp == NULL)//checking the file is open or not
        {
                printf("file can not be open for some resion :\n");
                return ;
        }


         fprintf(fp,"%s,%s,%c,%s,%s,%s,%s,%s,%s,%s,%s, ",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);//writing the new data in the xl file

        fclose(fp);//close the file

}


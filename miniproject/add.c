#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#include"main.h"
void empid_check();
void email_check(); 
void emp_details();
void display();

void xl_database_add(employee_data **head);

extern employee_data *head;
int flag=0;



void empid_check()
{
	employee_data *temp=head;
	char s[20];
	int k;
	while((temp->link)!=NULL)
	{
  	temp=temp->link;
	}
	printf("%s\n",temp->EMP_ID);
        strcpy(s,temp->EMP_ID);
	puts(s);
	k=atoi(s);
	k++;
	printf("%d\n",k);

}
char EMAIL_id[30];

void emp_details()
{		
	employee_data *new;	
	employee_data *temp1=head; //declaring new pointer variable to insert data
	new=(employee_data *)malloc(sizeof(employee_data));//allocating memory using malloc

	printf("Enter employee name:\n");
	scanf(" %[^\n]s",new->Name);		// Reading Employee Name from the user

	int count=0;
	while(count<3)
	{
	    printf("Enter gender(M or F):\n");          // Reading Employee Gender from the user
	    scanf(" %c",&new->GENDER);                   //checking entered input is correct or not
	    if(new->GENDER=='M' || new->GENDER=='F')
              break;
	    else
		count++;
	  if(count==3)
	    main();
	}


	printf("Enter employee Email_id:\n"); 
        scanf("%s",EMAIL_id);  // Reading Employee Email ID from the user
        while(temp1!=NULL)		
        {
                if(strcmp(temp1->EMAIL_ID,EMAIL_id)==0)//comparing employee id with existing id in excel sheet
                {
                        flag=1;//if equal flag is updated to 1 
                        break; //comes out of loop and prints id already exists
                }
                temp1=temp1->link;//else here temp is upadated

        }
        if(flag==1)
                printf("EMAIL ID  is already exist ! \nplesae enter again:\n");
        else 
	{
         memset(EMAIL_id,'\0',sizeof(EMAIL_id));//memset() is used to fill a block of memory with a particular value.
         strcpy(new->EMAIL_ID,EMAIL_id);
         }

	printf("Enter employee Band:\n");
	scanf(" %s",new->Band);   // Reading Employee Band from the user

	printf("Enter employee Date of joining dd/mm/yyyy:\n");
	scanf("%s",new->DOJ);	// Reading Employee Date of Joining from the user

	printf("Enter employee contact with +91:\n");
	scanf("\n%[^\n]s",new->Contact_No);	// Reading Employee Contact Number from the user

	printf("Enter Reporting Manager:\n");
	scanf(" %[^\n]s",new->Reporting_Manager);	// Reading Employee Reporting Manager Name from the user

	printf("Enter employee Technical Area:\n");
	scanf(" %[^\n]s",new->Tech_area);		// Reading Employee Technical Area from the user

	printf("Enter employee Project Info:\n");
	scanf(" %[^\n]s",new->Project_info);		// Reading Employee Project Info from the user

	printf("Enter a employee status: ");		
	scanf("\n%[^\n]s",new->Status);		//Reading Employee status

	xl_database_add(&new);			//database function call (Entered i/p is displayed in excel sheet)
	display();				//display function call(Entered data is displayed on console)
}


void display()		//Function to display Employee data
{
	employee_data *new=head;//to display data in excel sheet from begining to newly added data on console
	while(new!=NULL)
	{
		printf("%s %s %c %s %s  %s %s %s %s %s ",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager ,new->Tech_area,new->Project_info);
		new=new->link;
	}
}


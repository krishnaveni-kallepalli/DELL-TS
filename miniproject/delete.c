#include"header.h"
extern employee_data *head;


void delete_emp_info(employee_data *head1)
{
	int flag=0;//Declaring flag variable

	employee_data *temp=head1;//Assigning head pointer to temporary pointer(Inorder to not disturbing head pointer)

	char Delete_id[10];//Declaring Delete_id

//	char str[10]="\0";

	printf("enter which employee id you want to remove :\n");

	scanf("%s",Delete_id);//Reading Delete-id 


	while(temp!=NULL)//Checking address of emp_info
	{


	if((strcmp(temp->EMP_ID,Delete_id))==0)//Comapring Emp_id with ,employee data we want to delete
	{
	flag=1;//flag will 1 means employee id matches
	/*
	strcpy(temp->Name,str);
	temp->GENDER=' ';

	strcpy(temp->EMAIL_ID,str);

	strcpy(temp->DOJ,str);

	strcpy(temp-> Band,str);

	strcpy(temp->Contact_No,str);

	strcpy(temp->Reporting_Manager,str);

	strcpy(temp->Tech_area,str);

	strcpy(temp->Project_info,str);*/

	//Assigning NULL to all the information inorder to erase employye data(except Emp_id)
	
	if(strcmp(temp->Status,"Active")==0)//The employee status is Active,status will change to resigned
	{

	strcpy(temp->Status,"Resigned");//Status will changed to Resigned

	printf("Employee information removed \n");

	}
	else if(strcmp(temp->Status,"Termination")==0)//The status of employee Termination ,employee already terminated
	{

	printf("Employee already terminated \n");

	}
	else if(strcmp(temp->Status,"Suspension")==0)//The status of employee Suspension,employe already suspended
	{

	printf("Employee already suspended \n");

	}
	else//The employee not Active employee already Resigned
	{

	printf("Employee already Resigned \n");

	break;
	}

	}

	temp=temp->link;//traverse the list

	}
	if(flag==0)//flag will be zero ,emp_id not matches i,e emp_id not found

	{

	printf("Employee id not found \n");

	}


xl_delete_data(temp);
//	Display(&head);

}

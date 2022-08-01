#include"header.h"

/* ----------------------------  Function Description   ---------------------------------- */

/*

* Function Name: modify_employee_details function
-------------------------------------------------

* Author of the Function: K. Venkata Sneha and G. Chakrapani Reddy

* Description of the Function:
 Modify Details is selected, display a list of items which user can modify like Name, 
 Ph. No., Reporting Manger, Band, Reportees, Tech. Area and Project Info.

 Accept the item which needs to be modified and take input from user on that item.

 Update the collected information from user to database component for modification.	

* Other Functions used in this module:
 xl_database_modify(&temp);

 

* Function Name: modify_display function
----------------------------------------

* Author of the Function: K. Venkata Sneha and G. Chakrapani Reddy

* Description of the Function:
 	This function takes temp as argument and 
	Displays the Employee details of the particular Employee ID


* Function Name: modify_input function
--------------------------------------

* Author of the Function: K. Venkata Sneha and G. Chakrapani Reddy

* Description of the Function:
 	This function takes temp as argument and 
	taking modified Employee details from the user of Particular Employee ID

*/


unsigned char Id[100];


void modify_display(employee_data *temp)
{
	printf("\n\nDetails of the Employee whose ID is : %s\n",Id);
	printf("----------------------------------------------\n\n");
	printf("Employee ID 		 : %s\n",temp->EMP_ID);
	printf("Employee Name		 : %s\n",temp->Name);
	printf("Employee Gender		 : %c\n",temp->GENDER);
	printf("Employee Email ID 	 : %s\n",temp->EMAIL_ID);
	printf("Employee Band 		 : %s\n",temp->Band);
	printf("Employee Date oj joining : %s\n",temp->DOJ);
	printf("Employee Contact number	 : %s\n",temp->Contact_No);
	printf("Employee Tech Area	 : %s\n",temp->Tech_area);
	printf("Employee Project info	 : %s\n",temp->Project_info);
	printf("Employee Status 	 : %s\n",temp->Status);
	printf("\n\n");

}

void modify_input(employee_data *temp)
{
	int choice;
	unsigned char str[100];
	while(1)
	{    
		printf("\n\n1. EMP_ID\n2. Name\n3. Gender\n4. EMAIL_ID\n5. Band\n6. Date of joining\n7. Contact_number\n8. Reporting_manager\n9. Tech Area\n10. Project_info\n11. status\nPlease enter your choice to modify your details: ");

		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Sorry. You can't edit the Employee ID\n");
				//exit(0);  	// It will exit from the application
				break;    	// It will go back to main function
				//continue;	// It skip below lines and again ask the user choice to modify the details

			case 2:
				printf("Please Enter Employee Name: ");
				scanf("\n%[^\n]s",str);			// Reading Employee Name from the user
				strcpy(temp->Name,str);			// Copying of Employee Name into linked list
				printf("Employee Name modified successfully");
				break;
			case 3:
				printf("Sorry. You can't edit the Gender\n");
				break;
			case 4:
				printf("Sorry. You can't edit the Email ID\n");
				break; 
			case 5:
				printf("Please Enter Employee Band: ");
				scanf("%s",temp->Band);			// Reading Employee Band from the user
				printf("Employee Band modified successfully");
				break;

			case 6:
				printf("Sorry. You can't edit the Date of joining\n");
				break;

			case 7:
				printf("Please Enter Employee Contact_number: ");
				scanf("\n%[^\n]s",temp->Contact_No);	// Reading Employee Contact Number from the user
				printf("Employee Contact_number modified successfully");
				break;

			case 8:
				printf("Please Enter Employee Reporting_manager: ");
				scanf("\n%[^\n]s",temp->Reporting_Manager);	// Reading Employee Reporting Manager from the user
				printf("Employee Reporting_manager modified successfully");
				break;
			case 9:
				printf("Please Enter Employee Tech Area: ");
				scanf("\n%[^\n]s",temp->Tech_area);		// Reading Employee Tech Area from the user
				printf("Employee Tech Area modified successfully");
				break; 

			case 10:
				printf("Enter Employee Project_info: ");
				scanf("\n%[^\n]s",temp->Project_info);		// Reading Employee Project Info from the user
				printf("Employee Project_info modified successfully");
				break;

			case 11:
				printf("Please Enter Employee Status: ");
				scanf("\n%[^\n]s",temp->Status);		// Reading Employee Status from the user
				printf("Record modified successfully");
				break;
				
			default:
				printf("Invalid Selection");
				break;
		}
		break;	
	}


}

void modify_employee_details(employee_data **head)
{
	employee_data *temp;

	temp=*head;
	printf("\nEnter the Employee ID\n");
	scanf("%s",Id);			// Reading Employee ID from the user

	while(temp!=NULL)
	{
			if(strcmp(Id,temp-> EMP_ID))	// Comparing Employee ID with strcmp function
			{
				temp=temp->link;	// Traversing each node
				continue;
			}
			else
				break;			// If Employee ID Found, it will break from the loop
	}

	if(temp!=NULL)					// Traversing to the end
	{
		modify_display(temp);			// Calling modify_display(temp)

		modify_input(temp);			// Calling modify_input(&temp) function

		xl_database_modify(&temp);		// Calling xl_database_modify(&temp) function
	}
	else
	{
		printf("Sorry, Employee ID is not found\n");
	}
}	

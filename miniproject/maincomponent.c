#include"header.h"
void  main(void)
{
	int choice,wrong_opt=0;
//	ready_database(); //calling  read database
		 while(1)
	{
	printf("1.Add, 2.View, 3.Modify, 4.Delete, 5. Exit \n");
	printf("Please enter your choice\n:");
	scanf("%d",&choice); // taking input from the user
	 
		switch(choice) //switching between user input
		{
			case 1:
//				free(head); // free head
				ready_database(); //fun call for reading database
				empid_check();
		          	emp_details(); //fun call for add function
		          	free(head);
					      
		        	break;
		       /*case 2:

			      ready_database(); //fun call for reading database
			       view(); //function call for view function
			      free(head); //free head
			       break;*/
			case 3:
			       ready_database(); //calling read database
			       modify_employee_details(&head); //fun call for modify function
			       free(head);//free head

			       break;
			case 4:
			       ready_database(); //fun call ffor read database
			       delete_emp_info(head); //funcytion call for delete 
			   	free(head);   
			       break;
			case 5:
			      free(head); 
			       exit(0); //if user enter 5 it exit from the program
				  
			default:    // user have three chance to  check the valid data 
			      ++wrong_opt;

			      if(wrong_opt == 1)//if user enter invalid input first time
			      {
				      printf("You have two attempts only:\n");
				      continue;
			      }
			      else if(wrong_opt ==2)////if user enter invalid input second time
			      {
				      printf("You have only one attempt:\n");
				      continue;
			      }
			      else      //if user enter invalid input three times exiting from the program
				      printf("You have entered invalid  choice thrice, so exiting the application");
				      exit(0);
		}
	}
}

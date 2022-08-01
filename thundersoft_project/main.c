#include"header.h"
//extern employee_data *head;
void  main(void)
{
	int choice,wrong_opt=0;
	ready_database();
	 while(1)
	{
	printf("1.Add, 2.View, 3.Modify, 4.Delete, 5. Exit \n");
	printf("Please enter your choice\n:");
	scanf("%d",&choice);
	 
		switch(choice)
		{
			case 1:
				free(head);
				ready_database();
		          	add_func();
		          	
		      
		        	break;
		       case 2:

			      ready_database();
			     // xl_database();
			       view();
			      free(head);
			       break;
			case 3:
			       ready_database();
			       modify_employee_details(&head);
			       free(head);

			       break;
			case 4:
			       ready_database();
			       delete_emp_info(&head);
				free(head);
			      
			       break;
			case 5: exit(0);
				  break;
			default:
			      ++wrong_opt;

			      if(wrong_opt == 1)
			      {
				      printf("You have two attempts only:\n");
				      continue;
			      }
			      else if(wrong_opt ==2)
			      {
				      printf("You have only one attempt:\n");
				      continue;
			      }
			      else
				      printf("You have entered invalid  choice thrice, so exiting the application");
				      exit(0);
		}
	}
}


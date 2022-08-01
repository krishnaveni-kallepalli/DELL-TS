#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>


//......Global Employee Detail Structure........

typedef struct data
{
	char EMP_ID[10];
	char Name[40];
	char GENDER;
	char EMAIL_ID[30];
	char Band[3];
	char DOJ[15];
	char Contact_No[17];
	char Reporting_Manager[40];
	char Tech_area[20];
	char Project_info[20];
	char Status[15];
	struct data *link;
}employee_data;
void Display(employee_data **);//display function for local data base

//employee_data *head=NULL;

#include"main.h"
#include"add.h"
//#include"view.h"
#include"modify.h"
#include"delete.h"
#include"TSIndia_Emp_DB.h"

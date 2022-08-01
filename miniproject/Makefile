CC = gcc
CFLAGS = -c
exe: maincomponent.o add.o delete.o modify.o TSIndia_Emp_DB.o #-lpthread
	$(CC) maincomponent.c add.c delete.c modify.c -lpthread TSIndia_Emp_DB.c -o exe
maincomponent.o:maincomponent.c
	$(CC) $(CFLAGS) maincomponent.c
add.o:add.c
	$(CC) $(CFLAGS) add.c	
delete.o:delete.c
	$(CC) $(CFLAGS) delete.c  	
#add.o:add.c
#	$(CC) $(CFLAGS) add.c
modify.o:modify.c
	$(CC) $(CFLAGS) modify.c
#view.o:view.c 
#	$(CC) $(CFLAGS) view.c 
#modify.o:modify.c
#	$(CC) $(CFLAGS) modify.c
#delete.o:delete.c
#	$(CC) $(CFLAGS) delete.c	
TSIndia_Emp_DB.o:TSIndia_Emp_DB.c
	$(CC) $(CFLAGS) TSIndia_Emp_DB.c
clean:
	 rm *.o exe 


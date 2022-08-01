#final_build:maincomponent.o add.o view.o modify.o delete.o TSIndia_Emp_DB.o
#	gcc maincomponent.c add.c view.c modify.c delete.c -o final_build
#clean:
#	rm *.o


#cc=gcc
#final:
#	$(CC) maincomponent.c add.c view.c modify.c delete.c TSIndia_Emp_DB.c -o final

#clean:
#	rm -f final
#	CC = gcc

#CC = gcc
#CFLAGS = -C
#exe: maincomponent.o add.o view.o delete.o modify.o TSIndia_Emp_DB.o
#	$(CC) $^ -o $@
#.o:.c
#	$(CC) $(CFLAGS) $<
#clean:
#	rm *.o exe


CC = gcc
CFLAGS = -c
exe: main.o add.o delete.o modify.o view.o TSIndia_Emp_DB.o #-lpthread
	$(CC) main.c add.c delete.c modify.c view.c -lpthread TSIndia_Emp_DB.c -o exe
main.o:main.c
	$(CC) $(CFLAGS) main.c
add.o:add.c
	$(CC) $(CFLAGS) add.c	
delete.o:delete.c
	$(CC) $(CFLAGS) delete.c  	
#add.o:add.c
#	$(CC) $(CFLAGS) add.c
modify.o:modify.c
	$(CC) $(CFLAGS) modify.c
view.o:view.c 
	$(CC) $(CFLAGS) view.c 
#modify.o:modify.c
#	$(CC) $(CFLAGS) modify.c
#delete.o:delete.c
#	$(CC) $(CFLAGS) delete.c	
TSIndia_Emp_DB.o:TSIndia_Emp_DB.c
	$(CC) $(CFLAGS) TSIndia_Emp_DB.c
clean:
	 rm *.o exe 
#-- METHOD 8---
#CC=gcc
#CFLAGS= -C
#OBJS=maincomponent.o add.o delete.o modify.o view.o TSIndia_Emp_DB.o -lpthread

#HDR=header.h view.h add.h modify.h delete.h TS_India_Emp_DB.h main.h
#exe: $(OBJS) $(HDR)
#	$(CC) $(OBJS) - o exe
#maincomponent.o : maincomponent.c
#	$(CC) $(CFLAGS) maincomponent.c
#add.o:add.c
#	$(CC) $(CFLAGS) add.c
#delete.o:delete.c
#	$(CC) $(CFLAGS) delete.c
#modify.o : modify.c
#	$(CC) $(CFLAGS) modify.c
#view.o: view.c
#	$(CC) $(CFLAGS) view.c
#TSIndia_Emp_DB.o: TSIndia_Emp_DB.c
#	$(CC) $(CFLAGS) TSIndia_Emp_DB.c
#clean :
#	rm *.o
#	rm exe


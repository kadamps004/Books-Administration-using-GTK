project: book_master.c main_prog.c mains.h files.c filehandling.h main.c category_master.c group_master.c
	gcc main.c main_prog.c files.c book_master.c category_master.c  group_master.c -o project `pkg-config --cflags --libs gtk+-3.0`


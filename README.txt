	
	
	Project Title : Books Administration using GTK  (GTK3.0)
	
	Name : Priya Sanjay Kadam.
	
	MIS : 141603004
	

	
	This project is intended to implement the basic library management project . The code is written using GTK. GTK is GIMP ToolKit .  
It uses basic predefined functions of GTK library to implement few of the features. the project basically focuses on performing the following features :
			adding book entry
			updating book entry
			viewing the books.
	This features are implemented using the GTK library functions . Firstly , to understand the working of the project , basic knowledge of GTK is essential. the project exhibits total 7 screens - main screen, option screen, adding subject screen , adding semester screen , view screen and update screen . these screens are created using predefined functions . The data is written to a file and from the adding entry screen . Moreover, the data is also fetched back to the view screen and to the update screen . For this , basic file handling is managed in the code. for setting the data and getting back the data, here is the predefined function of GTK -   
	
	gtk_entry_set_text((GtkEntry *)book_master->txt_item_author, " ");
	gtk_entry_get_text((GtkEntry *)book_master->txt_item_author, " ");
	
	The project includes following files : main.c , main.h , files.c, files.h, book_master.c, category_master.c, group_master.c, and data folder which holds all the .txt files required in the project. The makefile is included in the folder. The main.c basically creates the first screen of the project , which includes options for the user to choose . from here , you can either go to manage books , add subject or add semester . the next file is main.h which includes the prototype of all functions used in main.c . for instance , 
	
	void book_master_activate(GtkApplication *app, Window_grid *win_grid);
	void book_master_populate(Book_master *book_master);
	void book_master_create(GtkWidget *widget, Book_master *book_master);
	void book_master_closing_fetch(GtkWidget *widget, Book_master *book_master);
	Book_master *book_master_add(GtkApplication *app, Window_grid *win_grid);
	void book_master_view(GtkApplication *app, Window_grid *win_grid);	
	void book_master_update(GtkApplication *app, Window_grid *win_grid);
	void book_master_display_fetch_data(GtkApplication *app, Book_master_display *master);


	this is required and must be included in the code . Most importantly , in main.c . The next is book_master.c , which provides user the options to return book i.e. add entry of book to the previously avaiable list . it also provides options like viewing the books, updating the booklist. from here you can also return to the main screen by clicking on Home button added on the screen . The next is category_master.c which allows user to create new subject to be added to the previously existing subject list. this screen also allows you to visit the main screen by clicking in home button placed in the screen . similarly , the group_master.c allows you to add Semester . the files.c and files.h are added to handle files . the basic operation of adding the data to a .txt file and again writing it back to screen is done by files.c . thr files.h includes the prototypes (signature) of all the functions used in files.c 
	This way the user can perform basic Library operations using this code . The code does not include the code for "deleting record" from existing record . the code intends to add entries , view entires and update entries only .  

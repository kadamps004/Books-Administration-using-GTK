/*****************************************************************************
 * "Books_Administration_using_GTK" 
 *
 * This code performs various operations mainly used in college book library.
 *
 * Copyright (C) 2017 Priya S. Kadam.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>
 *****************************************************************************/
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "mains.h"
#include "filehandling.h"


/*this function is called whenever user clicks on manage book records*/
void book_master_activate(GtkApplication *app, Window_grid *win_grid){
	GtkWidget *window, *book_master_grid;
	GtkWidget *label_title, *btn_add, *btn_update, *btn_view;
	GtkWidget *pad0, *pad1, *pad2, *pad3, *pad4, *pad5, *pad6, *pad7, *pad8, *pad9, *pad10, *pad11, *pad12, *pad13;
	int i = 0;
	GtkWidget *btn_home;
	
	
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	book_master_grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(win_grid->window), book_master_grid);
	win_grid->grid = book_master_grid;
	
	/*Set screen.*/
	win_grid->current_screen = MASTER;
	
	/*Creating pading labels*/
	pad0 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad0, 0, 0, 3, 1);
	
	/*Create title label.*/
	label_title = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_title), "<b><big><u>BOOK RECORDS</u></big></b>");
	gtk_grid_attach(GTK_GRID(book_master_grid), label_title, 0, 1, 3, 1);
	
	pad1 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad1, 0, 2, 3, 1);
	
	/*Creating buttons alongside padding.*/
	btn_add = gtk_button_new_with_label("Return book");
	pad2 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad2, 0, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(book_master_grid), btn_add, 1, 3, 1, 1);
	pad3 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad3, 2, 3, 1, 1);
	g_signal_connect(btn_add, "clicked", G_CALLBACK(book_master_add), win_grid);
	
	pad4 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad4, 0, 4, 3, 1);
	
	btn_update = gtk_button_new_with_label("Update books");
	pad5 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad5, 0, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(book_master_grid), btn_update, 1, 5, 1, 1);
	pad6 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad6, 2, 5, 1, 1);
	g_signal_connect(btn_update, "clicked", G_CALLBACK(book_master_update), win_grid);
	
	pad7 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad7, 0, 6, 3, 1);
	
	btn_view = gtk_button_new_with_label("View books");
	pad8 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad8, 0, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(book_master_grid), btn_view, 1, 7, 1, 1);
	pad9 = gtk_label_new("          ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad9, 2, 7, 1, 1);
	g_signal_connect(btn_view, "clicked", G_CALLBACK(book_master_view), win_grid);
	
	pad10 = gtk_label_new("         ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad10, 0, 8, 3, 1);
	
	btn_home = gtk_button_new_with_label("HOME");
	g_signal_connect(btn_home, "clicked", G_CALLBACK(activate), win_grid);
	gtk_grid_attach(GTK_GRID(book_master_grid), btn_home, 1, 10, 1, 1);
	
	pad13 = gtk_label_new("         ");
	gtk_grid_attach(GTK_GRID(book_master_grid), pad13, 0, 10, 3, 1);
	
	
	
	/*Make visible*/
	gtk_widget_show_all(win_grid->window);
	return;
}




Book_master *book_master_add(GtkApplication *app, Window_grid *win_grid){
	GtkWidget *window, *book_entry_grid;
	GtkWidget *label_item_title, *label_item_name, *label_item_code, *label_item_sem, *label_item_subject, *label_item_author, *label_item_price, *label_item_edition, *txt_item_edition;
	GtkWidget *btn_home;
	
	GtkWidget *pad1, *pad2, *pad3, *pad4, *pad5, *pad6, *pad7, *pad8, *pad9, *pad10;
	Book_master *book_master;
	
	book_master = (Book_master *)malloc(sizeof(Book_master));

	/*Remove screen.*/
	if(win_grid->grid)
		gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	book_entry_grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(win_grid->window), book_entry_grid);
	win_grid->grid = book_entry_grid;
	
	pad1 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad1, 0, 0, 2, 1);
	
	/*Title label.*/
	label_item_title = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_item_title), "<b><big>Book Records</big></b>\n");
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_title , 0, 1, 2, 1);
	
	pad2 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad2, 0, 2, 2, 1);
	
	
	label_item_name = gtk_label_new(NULL);
	gtk_label_set_markup_with_mnemonic(GTK_LABEL(label_item_name), "<big>Book Name : </big>");
	gtk_widget_set_halign(label_item_name, GTK_ALIGN_START);
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_name, 0, 5, 1, 1);
	
	pad3 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad3, 0, 4, 2, 1);
	
	label_item_code = gtk_label_new(NULL);
	gtk_label_set_markup_with_mnemonic(GTK_LABEL(label_item_code), "<big>ISBN : </big>");
	gtk_widget_set_halign(label_item_code, GTK_ALIGN_START);
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_code, 0, 3, 1, 1);
	
	pad4 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad4, 0, 6, 2, 1);
	
	label_item_sem = gtk_label_new(NULL);
	gtk_label_set_markup_with_mnemonic(GTK_LABEL(label_item_sem), "<big>_Semester : </big>");
	gtk_widget_set_halign(label_item_sem, GTK_ALIGN_START);
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_sem, 0, 7, 1, 1);
	
	pad5 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad5, 0, 8, 2, 1);	
	
	label_item_subject = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_item_subject), "<big>Subject : </big>");
	gtk_widget_set_halign(label_item_subject, GTK_ALIGN_START);
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_subject, 0, 9, 1, 1);
	
	pad6 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad6, 0, 10, 2, 1);
	
	label_item_author = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_item_author), "<big>Author : </big>");
	gtk_widget_set_halign(label_item_author, GTK_ALIGN_START);
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_author, 0, 11, 1, 1);
	
	pad7 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad7, 0, 12, 2, 1);
		
	label_item_price = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_item_price), "<big>Price : </big>");
	gtk_widget_set_halign(label_item_price, GTK_ALIGN_START);
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_price, 0, 13, 1, 1);
	
	pad8 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad8, 0, 14, 2, 1);
	
	label_item_edition = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_item_edition), "<big>Edition : </big>");
	gtk_widget_set_halign(label_item_edition, GTK_ALIGN_START);
	gtk_grid_attach(GTK_GRID(book_entry_grid), label_item_edition, 0, 15, 1, 1);
	
	pad9 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad9, 0, 16, 2, 1);
	
	btn_home = gtk_button_new_with_label("HOME");
	g_signal_connect(btn_home, "clicked", G_CALLBACK(activate), win_grid);
	gtk_grid_attach(GTK_GRID(book_entry_grid), btn_home, 0, 21, 1, 1);
	
	
	pad10 = gtk_label_new("   ");
	gtk_grid_attach(GTK_GRID(book_entry_grid), pad10, 0, 18, 2, 1);
	
	
	
	/*Creating boxes.*/
	book_master->txt_item_name = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->txt_item_name, 1, 5, 1, 1);
	
	book_master->txt_item_code = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->txt_item_code, 1, 3, 1, 1);
	
	
	book_master->txt_item_author = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->txt_item_author, 1, 11, 1, 1);
	
	book_master->txt_item_edition = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->txt_item_edition, 1, 15, 1, 1);
	
	book_master->txt_item_price = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(book_master->txt_item_price), 4);
	gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->txt_item_price, 1, 13, 1, 1);	
	
	/*Dropdowns.*/
	book_master->combo_item_sem = gtk_combo_box_text_new();
	book_master->combo_item_subject = gtk_combo_box_text_new();
	
	
	gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->combo_item_sem, 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->combo_item_subject, 1, 9, 1, 1);
	
	
	book_master_populate(book_master);

	g_print("Current : %d\n MASTER_SUB : %d\n", win_grid->current_screen, MASTER_SUB_UPDATE);
	if(win_grid->current_screen == MASTER_SUB_UPDATE){
		g_print("inside if\n");
		book_master->btn_item_update = gtk_button_new_with_label("UPDATE");
		book_master->btn_item_submit = NULL;
		gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->btn_item_update, 1, 21, 1, 1);
		g_signal_connect(book_master->btn_item_submit, "clicked", G_CALLBACK(book_master_display_fetch_data), book_master);
	}
	else{
		g_print("inside elase\n");
		book_master->btn_item_update = NULL;
		book_master->btn_item_submit = gtk_button_new_with_label("CREATE");
		gtk_grid_attach(GTK_GRID(book_entry_grid), book_master->btn_item_submit, 1, 21, 1, 1);
		 
		g_signal_connect(book_master->btn_item_submit, "clicked", G_CALLBACK(book_master_create), book_master);
	}
	
	
	/*Make all visible.*/
	gtk_widget_show_all(win_grid->window);	
	
	return book_master;
}

/*populate function*/
void book_master_populate(Book_master *user_master){
	int i = 0, j = 0, count = 0;
	FILE *fp_grp, *fp_cat;
	int size_grp, size_cat;
	char *sem, *subject;
	
	fp_grp = fopen("Semester.txt", "r");
	fp_cat = fopen("Subject.txt", "r");
	
	while(fread(&size_grp, sizeof(int), 1, fp_grp)){
		sem = (char *)malloc(sizeof(char)*size_grp);
		fread(sem, (sizeof(char) * size_grp), 1, fp_grp);
		sem[size_grp] = '\0';
		gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(user_master->combo_item_sem), NULL, sem);
		free(sem);
		sem = NULL;
	}
	
	/* category dropdown.*/
	while(fread(&size_cat, sizeof(int), 1, fp_cat)){
		subject = (char *)malloc(sizeof(char)*size_cat);
		fread(subject, (sizeof(char) * size_cat), 1, fp_cat);
		subject[size_cat] = '\0';
		gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(user_master->combo_item_subject), NULL, subject);
		free(subject);
		subject = NULL;
	}
	
	fclose(fp_grp);
	fclose(fp_cat);
	return;
}

void book_master_closing_fetch(GtkWidget *widget, Book_master *book_master){
	
}

/*this is a function that writes to a file*/
void book_master_create(GtkWidget *widget, Book_master *book_master){
	Book_master_info info;
	
	info.name = gtk_entry_get_text((GtkEntry *)book_master->txt_item_name);
	info.code = gtk_entry_get_text((GtkEntry *)book_master->txt_item_code);
	info.author = gtk_entry_get_text((GtkEntry *)book_master->txt_item_author);
	info.price = gtk_entry_get_text((GtkEntry *)book_master->txt_item_price);
	info.edition = gtk_entry_get_text((GtkEntry *)book_master->txt_item_edition);
	info.sem = gtk_combo_box_text_get_active_text((GtkComboBoxText *)book_master->combo_item_sem);
	info.subject = gtk_combo_box_text_get_active_text((GtkComboBoxText *)book_master->combo_item_subject);
	
	write_book_master_info(&info);
	g_print("Inside Item master create : \n");
	g_print("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", info.name, info.code, info.author, info.price, info.edition, info.sem, info.subject);
	
	/*Clear data*/
	gtk_entry_set_text((GtkEntry *)book_master->txt_item_name, " ");
	gtk_entry_set_text((GtkEntry *)book_master->txt_item_code, " ");
	gtk_entry_set_text((GtkEntry *)book_master->txt_item_author, " ");
	gtk_entry_set_text((GtkEntry *)book_master->txt_item_price, " ");
	gtk_entry_set_text((GtkEntry *)book_master->txt_item_edition, " ");

	return;
}


void book_master_view(GtkApplication *app, Window_grid *win_grid){
	GtkWidget *view_window, *window, *label_title, *grid;
	GtkAdjustment *adj;
	GtkWidget *label_name, *label_code, *label_sem, *label_subject, *label_author, *label_price, *label_edition;
	GtkWidget *padding0, *padding1, *padding2, *padding3, *padding4, *padding5, *padding6, *padding7, *padding8, *padding9;
	FILE *fp;
	int i = 0, size_sem, size_subject, size_name, j, size_author;
	long long int code;
	float price;
	int edition;
	char *sem, *subject, *name, *author, code_str[16], edition_str[20], price_str[20], ch;
	Book_master_display *master[MAX_VIEW];
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	
	view_window = gtk_scrolled_window_new(NULL, NULL);
	
	grid = gtk_grid_new();
	
	
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(view_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	
	gtk_container_add(GTK_CONTAINER(view_window), grid);
	gtk_container_add(GTK_CONTAINER(window), view_window);
	
	gtk_widget_show(view_window);
	gtk_window_set_default_size(GTK_WINDOW(window), 1200, 1000);
	
	padding0 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(grid), padding0, 0, 0, 12, 1);
	
	
	label_title = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_title), "<b><big><u>Existing Books Record</u></big></b>");
	gtk_grid_attach(GTK_GRID(grid), label_title, 0, 1, 12, 1);
	
	padding1 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(grid), padding1, 0, 2, 12, 1);
	
	/*Creating labels.*/
	label_code = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_code), "<b>ISBN</b>"); 
	gtk_grid_attach(GTK_GRID(grid), label_code, 0, 3, 1, 1);
	
	padding2 = gtk_label_new("        ");
	gtk_grid_attach(GTK_GRID(grid), padding2, 1, 3, 1, 1);
	
	label_name = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_name), "<b>Book Name</b>");
	gtk_grid_attach(GTK_GRID(grid), label_name, 2, 3, 1, 1);
	
	padding3 = gtk_label_new("        ");
	gtk_grid_attach(GTK_GRID(grid), padding3, 3, 3, 1, 1);
	
	label_sem = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_sem), "<b>Group</b>");
	gtk_grid_attach(GTK_GRID(grid), label_sem, 4, 3, 1, 1);
	
	padding4 = gtk_label_new("        ");
	gtk_grid_attach(GTK_GRID(grid), padding4, 5, 3, 1, 1);
	
	label_subject = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_subject), "<b>Category</b>");
	gtk_grid_attach(GTK_GRID(grid), label_subject, 6, 3, 1, 1);
	
	padding5 = gtk_label_new("        ");
	gtk_grid_attach(GTK_GRID(grid), padding5, 7, 3, 1, 1);
	
	label_author = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_author), "<b>Author</b>");
	gtk_grid_attach(GTK_GRID(grid), label_author, 8, 3, 1, 1);
	
	padding6 = gtk_label_new("        ");
	gtk_grid_attach(GTK_GRID(grid), padding6, 9, 3, 1, 1);
	
	label_price = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_price), "<b>Price</b>");
	gtk_grid_attach(GTK_GRID(grid), label_price, 10, 3, 1 ,1);
	
	padding7 = gtk_label_new("        ");
	gtk_grid_attach(GTK_GRID(grid), padding7, 11, 3, 1, 1);
	
	label_edition = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_edition), "<b>Edition</b>");
	gtk_grid_attach(GTK_GRID(grid), label_edition, 12, 3, 1, 1);
	
	padding8 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(grid), padding8, 0, 4, 12, 1);
	
	padding9 = gtk_label_new("        ");
	gtk_grid_attach(GTK_GRID(grid), padding9, 13, 3, 1, 1);
		
	fp = fopen("Addbook.txt", "a+");
	
	j = 5;
	i = 0;
	
	while(fread(&code, sizeof(long long int), 1, fp)){
	
		master[i] = (Book_master_display *)malloc(sizeof(Book_master_display));
		
		printf("Inside if\n");
		printf("Code : %lld\n", code);
		master[i]->label_txt_code = gtk_label_new(NULL);
		sprintf(code_str, "%lld", code);
		
		gtk_label_set_text(GTK_LABEL(master[i]->label_txt_code), code_str);
		gtk_grid_attach(GTK_GRID(grid), master[i]->label_txt_code, 0, j, 1, 1);

		fread(&ch, sizeof(char), 1, fp);
			
		master[i]->label_txt_sem = gtk_label_new(NULL);		
		fread(&size_sem, sizeof(int), 1, fp);
		sem = (char *)malloc(sizeof(char) * size_sem + 1);
		fread(sem, sizeof(char), size_sem, fp);
		sem[size_sem] = '\0';
		gtk_label_set_text(GTK_LABEL(master[i]->label_txt_sem), sem);
		gtk_grid_attach(GTK_GRID(grid), master[i]->label_txt_sem, 4, j, 1, 1);
		
		
		master[i]->label_txt_subject = gtk_label_new(NULL);
		fread(&size_subject, sizeof(int),1, fp);
		subject = (char *)malloc(sizeof(char) * size_subject + 1);
		fread(subject, sizeof(char), size_subject, fp);
		subject[size_subject] = '\0';
		gtk_label_set_text(GTK_LABEL(master[i]->label_txt_subject), subject);
		gtk_grid_attach(GTK_GRID(grid), master[i]->label_txt_subject, 6, j, 1, 1);
		
		
		master[i]->label_txt_name = gtk_label_new(NULL);
		fread(&size_name, sizeof(int),1, fp);
		name = (char *)malloc(sizeof(char) * size_name + 1);
		fread(name, sizeof(char), size_name, fp);
		name[size_name] = '\0';
		gtk_label_set_text(GTK_LABEL(master[i]->label_txt_name), name);
		gtk_grid_attach(GTK_GRID(grid), master[i]->label_txt_name, 2, j, 1, 1);
		
	
		

		master[i]->label_txt_price = gtk_label_new(NULL);		
		fread(&price, sizeof(float), 1, fp);
		sprintf(price_str, "%f", price);
		gtk_label_set_text(GTK_LABEL(master[i]->label_txt_price), price_str);
		gtk_grid_attach(GTK_GRID(grid), master[i]->label_txt_price, 10, j, 1, 1);
		
		master[i]->label_txt_edition = gtk_label_new(NULL);
		fread(&edition, sizeof(int), 1, fp);
		sprintf(edition_str, "%d", edition);
		gtk_label_set_text(GTK_LABEL(master[i]->label_txt_edition), edition_str);
		gtk_grid_attach(GTK_GRID(grid), master[i]->label_txt_edition, 12, j, 1, 1);
		
		master[i]->label_txt_author = gtk_label_new(NULL);
		fread(&size_author, sizeof(int), 1, fp);
		author = (char *)malloc(sizeof(char) * size_author + 1);
		fread(author, sizeof(char), size_author, fp);
		author[size_author] = '\0';
		gtk_label_set_text(GTK_LABEL(master[i]->label_txt_author), author);
		gtk_grid_attach(GTK_GRID(grid), master[i]->label_txt_author, 8, j, 1, 1);
		
		
		 
		
		if(win_grid->current_screen == MASTER_SUB_UPDATE){
			master[i]->btn_select = gtk_button_new_with_label("UPDATE");
			gtk_grid_attach(GTK_GRID(grid), master[i]->btn_select, 14, j, 1, 1);
			g_signal_connect(master[i]->btn_select, "clicked", G_CALLBACK(book_master_display_fetch_data), master[i]);
		}
		
		free(sem);
		free(subject);
		free(name);
		free(author);
		
		i++;
		j++;
		
	}
	
	fclose(fp);
	gtk_widget_show_all(view_window);
	gtk_widget_show_all(window);
	return;

}

/*updation function.*/
void book_master_update(GtkApplication *app, Window_grid *win_grid){
	GtkWidget *update_window, *view_window;
	
	win_grid->current_screen = MASTER_SUB_UPDATE;
	

	view_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	win_grid->window = view_window;
	book_master_view(win_grid->application, win_grid);
	
	return;
}

void book_master_display_fetch_data(GtkApplication *app, Book_master_display *master){
	GtkWidget *update_window, *update_grid, *btn_item_update;
	GtkWidget *label_title, *label_name1, *label_name2, *label_code1, *label_sem1, *label_subject1, *label_subject2, *label_author1, *label_author2, *label_price, *label_edition;
	GtkWidget *pad0, *pad1, *pad2, *pad3, *pad4, *pad5, *pad6, *pad7, *pad8, *pad9;//, *pad10;
	float fetch_price;
	int fetch_edition;
	long long int fetch_code;
	Window_grid *win_grid;
	Book_master_update *book_master_update;
	
	book_master_update = (Book_master_update *)malloc(sizeof(Book_master_update));
	

	win_grid = (Window_grid *)malloc(sizeof(Window_grid));

	
	g_print("Inside Item Master display fetch data\n");
	
	update_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	update_grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(update_window), update_grid);
	
	win_grid->window = update_window;
	win_grid->grid = update_grid;
	win_grid->application = app;
	win_grid->current_screen = MASTER_SUB_UPDATE;
	
	pad0 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad0, 0, 0, 2, 1);
	
	label_title = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_title), "<b><big>UPDATE RECORD</big></b>");
	gtk_grid_attach(GTK_GRID(update_grid), label_title, 0, 1, 2, 1);
	
	pad1 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad1, 0, 2, 2, 1);
	
	label_code1 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_code1), "<big>Code : </big>");
	gtk_grid_attach(GTK_GRID(update_grid), label_code1, 0, 3, 1, 1);
	
	book_master_update->label_code2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid),book_master_update->label_code2, 1, 3, 1, 1);

	pad2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad2,  0, 4, 2, 1);
	
	label_name1 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_name1), "<big>Name : </big>");
	gtk_grid_attach(GTK_GRID(update_grid), label_name1, 0, 5, 1, 1);
	
	label_name2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), label_name2, 1, 5, 1, 1);
	
	pad3 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad3, 0, 6, 2, 1);
	
	label_sem1 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_sem1), "<big>Semester : </big>");
	gtk_grid_attach(GTK_GRID(update_grid), label_sem1, 0, 7, 1, 1);
	
	book_master_update->label_sem2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), book_master_update->label_sem2, 1, 7, 1, 1);
	
	pad4 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad4, 0, 8, 2, 1);
	
	label_subject1 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_subject1), "<big>Subject : </big>");
	gtk_grid_attach(GTK_GRID(update_grid), label_subject1, 0, 9, 1, 1);
	
	label_subject2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), label_subject2, 1, 9, 1, 1);
	
	pad5 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad5, 0, 10, 2, 1);
	
	label_author1 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_author1), "<big>Author : </big>");
	gtk_grid_attach(GTK_GRID(update_grid), label_author1, 0, 11, 1, 1);
	
	label_author2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), label_author2, 1, 11, 1, 1);
	
	pad6 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad6, 0, 12, 2, 1);
	
	label_price = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_price), "<big>Price : </big>");
	gtk_grid_attach(GTK_GRID(update_grid), label_price, 0, 13, 1, 1);
	
	book_master_update->txt_price = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(update_grid), book_master_update->txt_price, 1, 13, 1, 1);
	
	pad7 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad7, 0, 14, 2, 1);

	label_edition = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_edition), "<big>Edition : </big>");
	gtk_grid_attach(GTK_GRID(update_grid), label_edition, 0, 15, 1, 1);
	
	book_master_update->txt_edition = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(update_grid), book_master_update->txt_edition, 1, 15, 1, 1);
	
	pad8 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad6, 0, 16, 2, 1);
	
	gtk_label_set_text((GtkLabel *)label_name2, gtk_label_get_text(GTK_LABEL(master->label_txt_name)));
	gtk_label_set_text((GtkLabel *)label_author2, gtk_label_get_text(GTK_LABEL(master->label_txt_author)));
	gtk_entry_set_text((GtkEntry *)book_master_update->txt_price, gtk_label_get_text(GTK_LABEL(master->label_txt_price)));
	gtk_entry_set_text((GtkEntry *)book_master_update->txt_edition, gtk_label_get_text(GTK_LABEL(master->label_txt_edition)));
	gtk_label_set_text((GtkLabel *)book_master_update->label_code2, gtk_label_get_text(GTK_LABEL(master->label_txt_code)));
	gtk_label_set_text((GtkLabel *)book_master_update->label_sem2, gtk_label_get_text(GTK_LABEL(master->label_txt_sem)));
	gtk_label_set_text((GtkLabel *)label_subject2, gtk_label_get_text(GTK_LABEL(master->label_txt_subject)));
	
	pad9 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(update_grid), pad9, 0, 17, 2, 1);
	
	btn_item_update = gtk_button_new_with_label("UPDATE");
	gtk_grid_attach(GTK_GRID(update_grid), btn_item_update, 1, 18, 1, 1);
	
	g_print("Now calling item_master write update\n");
	
	g_signal_connect(btn_item_update, "clicked", G_CALLBACK(book_master_write_update), book_master_update);
	gtk_widget_show_all(update_window);
	return;	
}


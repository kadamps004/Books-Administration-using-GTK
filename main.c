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

/*This is a GTK program for managing book records */
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <gdk/gdkkeysyms.h>
#include <errno.h>
#include "mains.h"
#include "filehandling.h"


GtkWidget *init_window(GtkApplication *app){
	GtkWidget *window;
	window = gtk_application_window_new(app);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_title(GTK_WINDOW(window), "Books Administration");	
	return window;
}

	


void activate(GtkApplication *app, Window_grid *win_grid){
	GtkWidget *main_grid;
	GtkWidget *btn_manage_books;
	GtkWidget *btn_add; 
	GtkWidget *btn_add_g;
	
	GtkWidget *label_padding1, *label_padding2, *label_pad3, *label_pad4, *label_pad5, *pad1, *pad2, *label_main_title;
	
	//set_default_size can be used to set the default sixe to the screen , it requires static declaration of activate function . 
	
	//gtk_window_set_default_size (GTK_WINDOW (window), 200, 200); 
	Window_grid *menu;
	// to get back on homescreen whenever home button is clicked

  	if(!win_grid){
  		menu = (Window_grid *)malloc(sizeof(Window_grid));
  	
			
 		menu->window = init_window(app);
 		gtk_window_set_title(GTK_WINDOW(menu->window), "BOOKS GATEWAY");
			
 		menu->grid = gtk_grid_new();
		gtk_container_add(GTK_CONTAINER(menu->window), menu->grid);
	}
	else{
		menu = win_grid;
		gtk_container_remove(GTK_CONTAINER(menu->window), menu->grid);
		main_grid = gtk_grid_new();
		gtk_container_add(GTK_CONTAINER(menu->window), main_grid);
		menu->grid = main_grid;
	}
	if(!win_grid){
		menu = (Window_grid *)malloc(sizeof(Window_grid));
	
		
		menu->window = init_window(app);
		gtk_window_set_title(GTK_WINDOW(menu->window), "BOOKS ADMINISTRATION");
		menu->application = app;			
		menu->grid = gtk_grid_new();
		gtk_container_add(GTK_CONTAINER(menu->window), menu->grid);
	}
	
	else{
	
		menu = win_grid;
		
		gtk_container_remove(GTK_CONTAINER(menu->window), menu->grid);
		
		main_grid = gtk_grid_new();
		gtk_container_add(GTK_CONTAINER(menu->window), main_grid);
		menu->grid = main_grid;
	}
	/*Set screen*/
	menu->current_screen = HOME;
	
	label_padding1 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(menu->grid), label_padding1, 0, 1, 3, 1);
	
	label_main_title = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_main_title), "<b><big>BOOKS ADMINISTRATION</big></b>");
	gtk_grid_attach(GTK_GRID(menu->grid), label_main_title, 0, 2, 3, 1);
	
	label_padding2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(menu->grid), label_padding2, 0, 3, 3, 1);
	
	pad1 = gtk_label_new("               ");
	gtk_grid_attach(GTK_GRID(menu->grid), pad1, 0, 4, 1, 1);
	
	/*Creating buttons.*/
	btn_manage_books = gtk_button_new_with_label(" MANAGE BOOK RECORD ");
	gtk_grid_attach(GTK_GRID(menu->grid), btn_manage_books, 1, 4, 1, 1);
	g_signal_connect(btn_manage_books, "clicked", G_CALLBACK(book_master_activate), menu);
	
	pad2 = gtk_label_new("              ");
	gtk_grid_attach(GTK_GRID(menu->grid), pad2, 2, 4, 1, 1);
	
	label_pad3 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(menu->grid), label_pad3, 0, 5, 1, 1);
	
	btn_add = gtk_button_new_with_label("ADD SUBJECT");
	gtk_grid_attach(GTK_GRID(menu->grid), btn_add, 1, 6, 1, 1);
	g_signal_connect(btn_add, "clicked", G_CALLBACK(subject_master_activate), menu);
	
	label_pad4 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(menu->grid), label_pad4, 0, 7, 1, 1);
	
	btn_add_g = gtk_button_new_with_label("ADD SEMESTER");
	gtk_grid_attach(GTK_GRID(menu->grid), btn_add_g, 1, 8, 1, 1);
	g_signal_connect(btn_add_g, "clicked", G_CALLBACK(sem_master_activate), menu);
	
	label_pad5 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(menu->grid), label_pad5, 0, 9, 1, 1);
	
	
	gtk_widget_show_all(menu->window);	
}





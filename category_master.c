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
#include "mains.h"
#include "filehandling.h"

void subject_master_activate(GtkApplication *app, Window_grid *win_grid){
	GtkWidget *window, *category_master_grid;
	GtkWidget *label_subject_master_title, *label_subject, *txt_subject, *label_padding1, *label_padding2, *label_padding3, *label_padding4, *label_padding5;
	GtkWidget *btn_create;
	GtkWidget *btn_home;
	/*Create a grid .*/
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	category_master_grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(win_grid->window), category_master_grid);
	win_grid->grid = category_master_grid;
	
	win_grid->current_screen = MASTER;
	
	label_padding1 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(category_master_grid), label_padding1, 0, 0, 1, 2);
	
	/*title label.*/
	label_subject_master_title = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_subject_master_title), "<u><b><big>ADD SUBJECT</big></b></u>\n");
	gtk_grid_attach(GTK_GRID(category_master_grid), label_subject_master_title , 1, 1, 1, 2);
	
	label_padding2 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(category_master_grid), label_padding1, 2, 2, 1, 2);
	
	label_subject = gtk_label_new("Subject : ");
	gtk_grid_attach(GTK_GRID(category_master_grid), label_subject, 1, 3, 1, 1);
	
	txt_subject = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(category_master_grid), txt_subject, 2, 3, 1, 1);
	
	label_padding3 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(category_master_grid), label_padding3, 4, 4, 2, 1);
	
	/*Create an instance of a button.*/
	btn_create = gtk_button_new_with_label("CREATE");
	g_signal_connect(btn_create, "clicked", G_CALLBACK(subject_master_create), txt_subject);
	gtk_grid_attach(GTK_GRID(category_master_grid), btn_create, 2, 5, 1, 1);
	
	label_padding4 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(category_master_grid), label_padding4, 6, 6, 2, 1);
	
	/*click on home button to go to the previous visited screen*/
	btn_home = gtk_button_new_with_label("HOME");
	g_signal_connect(btn_home, "clicked", G_CALLBACK(activate), win_grid);
	gtk_grid_attach(GTK_GRID(category_master_grid), btn_home, 2, 7, 1, 1);
	
	label_padding5 = gtk_label_new(NULL);
	gtk_grid_attach(GTK_GRID(category_master_grid), label_padding5, 8, 8, 2, 1);
	

		
	/*Make all visible.*/
	gtk_widget_show_all(win_grid->window);
	
}

void subject_master_create(GtkWidget *widget, GtkWidget *txt_subject){
	const gchar *subject;
 	subject = gtk_entry_get_text((GtkEntry *)txt_subject);
 	 
 	/*Write info.*/
 	if(subject[0] != '\0')
 		write_c_master_info(subject);

	/*Clearingd data.*/
 	gtk_entry_set_text((GtkEntry *)txt_subject, " ");
 	
	return;
	
}


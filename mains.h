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
#ifndef __MAINS__H
#define __MAINS__H

#define MAXIMUM 50
#define MAX_VIEW 2000

#define MAX_ARR 1999

#define HOME 1
#define MASTER 2
#define MASTER_SUB 3
#define MASTER_SUB_UPDATE 4

typedef struct Window_grid{
	GtkWidget *window, *grid;
	GtkApplication *application;
	int current_screen;
}Window_grid;

typedef struct book_master_display{
	GtkWidget *label_txt_name, *label_txt_code, *label_txt_sem, *label_txt_subject, *label_txt_price, *label_txt_edition, *label_txt_author, *btn_select;
}Book_master_display;


typedef struct Book_master{
	GtkWidget *txt_item_name, *txt_item_code, *txt_item_author, *txt_item_price, *txt_item_edition;
	GtkWidget *combo_item_sem, *combo_item_subject; 
	GtkWidget *btn_item_submit, *btn_item_update;
}Book_master;

typedef struct Book_master_data_win{
	Book_master *book_master;
	Window_grid *win_grid;
}Book_master_data_win;


GtkWidget *init_window(GtkApplication *app);

void activate(GtkApplication *app, Window_grid *win_grid);


/*prototype of all functions*/
void book_master_activate(GtkApplication *app, Window_grid *win_grid);
void book_master_populate(Book_master *book_master);
void book_master_create(GtkWidget *widget, Book_master *book_master);
void book_master_closing_fetch(GtkWidget *widget, Book_master *book_master);
Book_master *book_master_add(GtkApplication *app, Window_grid *win_grid);
void book_master_view(GtkApplication *app, Window_grid *win_grid);
void book_master_update(GtkApplication *app, Window_grid *win_grid);
void book_master_display_fetch_data(GtkApplication *app, Book_master_display *master);

void sem_master_activate(GtkApplication *app, Window_grid *win_grid);
void sem_master_create(GtkWidget *widget, GtkWidget *txt_sem);

void subject_master_activate(GtkApplication *app, Window_grid *win_grid);
void subject_master_create(GtkWidget *widget, GtkWidget *txt_subject);


#endif

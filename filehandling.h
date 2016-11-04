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
#ifndef __FILEHANDLING__H
#define __FILEHANDLING__H
#include "mains.h"

#define MAX_STR 150

typedef struct Book_master_info{
	const gchar *name, *code, *author, *price, *edition, *sem, *subject;
}Book_master_info;

typedef struct Book_master_update{
	GtkWidget  *txt_price, *txt_edition, *label_code2, *label_sem2;
}Book_master_update;


/*prototype of all the used functions*/
void write_g_master_info(const gchar *group);
void write_c_master_info(const gchar *category);
void write_book_master_info(Book_master_info *info);
void book_master_write_update(GtkWidget *widget, Book_master_update *book_master_update);

#endif

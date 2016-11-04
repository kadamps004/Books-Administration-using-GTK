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
#include <stdio.h>
#include <gtk/gtk.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"

void write_g_master_info(const gchar *sem){
	int size_grp;
	FILE *fp;
	char grp[MAX_STR];
	
	/*opening file*/
	fp = fopen("Semester.txt", "a+");
	
	strcpy(grp, (char *)sem);

	size_grp = strlen(grp);
	
	fwrite(&size_grp, sizeof(int), 1, fp);
	fprintf(fp, "%s", grp);
	
	/*Closing file.*/
	fclose(fp);	
	
	return;
}

void write_c_master_info(const gchar *subject){
	int size_cat;
	FILE *fp;
	char cat[MAX_STR];
	
	/*Open the file to which the data is to be written*/
	fp = fopen("Subject.txt", "a+");
	
	strcpy(cat, (char *)subject);
	
	size_cat = strlen(cat);
	
	fwrite(&size_cat, sizeof(int), 1, fp);
	fprintf(fp, "%s", cat);
	
	/*Close the file.*/
	fclose(fp);
	
	return;	
}

void write_book_master_info(Book_master_info *info){
	int size_name, size_grp, size_cat, size_author;
	FILE *fp1, *fp2;
	char name[MAX_STR], grp[MAX_STR], cat[MAX_STR], file_name[MAX_STR], author[MAX_STR];
	long long int code;
	float price;
	int edition;
	char padding = 'p';
	
	/*create file.*/
	//strcpy(file_name, "");
	strcat(file_name, info->sem);
	strcat(file_name, "Addbook.txt");
	
	fp1 = fopen(file_name, "a+");
	fp2 = fopen("Addbook.txt", "a+");
	
	strcpy(name, (char *)info->name);
	strcpy(grp, (char *)info->sem);
	strcpy(cat, (char *)info->subject);
	strcpy(author, (char *)info->author);
	
	/*length of the strings.*/
	size_name = strlen(name);
	size_grp = strlen(grp);
	size_cat = strlen(cat);
	size_author = strlen(author);
	
	/*Convert the data .*/
	/*atoll since its long long int*/
	code = atoll(info->code);
	/*atof since its float*/
	price = atof(info->price);
	/*atoi since its only int*/
	edition = atoi(info->edition);
	
	/*Write data to the particular group file*/
	fwrite(&code, sizeof(long long int), 1, fp1);
	fwrite(&padding, sizeof(char), 1, fp1);
	
	fwrite(&size_cat, sizeof(int), 1, fp1);
	fprintf(fp1, "%s", cat);
	
	fwrite(&size_name, sizeof(int), 1, fp1);
	fprintf(fp1, "%s", name);
	
	fwrite(&price, sizeof(float), 1, fp1);
	
	fwrite(&edition, sizeof(int), 1, fp1);
	
	fwrite(&size_author, sizeof(int), 1, fp1);
	fprintf(fp1, "%s", author);
	
	/*write data*/
	fwrite(&code, sizeof(long long int), 1, fp2);
	fwrite(&padding, sizeof(char), 1, fp2);
	
	fwrite(&size_grp, sizeof(int), 1, fp2);
	fprintf(fp2, "%s", grp);
	
	fwrite(&size_cat, sizeof(int), 1, fp2);
	fprintf(fp2, "%s", cat);
	
	fwrite(&size_name, sizeof(int), 1, fp2);
	fprintf(fp2, "%s", name);
	
	fwrite(&price, sizeof(float), 1, fp2);
	
	fwrite(&edition, sizeof(int), 1, fp2);
	
	fwrite(&size_author, sizeof(int), 1, fp2);
	fprintf(fp2, "%s", author);
	
	
	fclose(fp1);
	fclose(fp2);
	
	return;
}

void book_master_write_update(GtkWidget *widget, Book_master_update *book_master_update){
	FILE *fp1, *fp2;
	const gchar *sem;
	char group_file[MAX_STR], *sem1, *subject1, *name1, *author1, ch;
	float price, price1;
	int edition, edition1;
	long long int code, code1;
	int size_name, size_sem, size_subject, size_author;

	/*fetching dtaa*/
	sem = gtk_label_get_text((GtkLabel *)book_master_update->label_sem2);
	
	
	price = atof(gtk_entry_get_text((GtkEntry *)book_master_update->txt_price));
	edition = atoi(gtk_entry_get_text((GtkEntry *)book_master_update->txt_edition));
	code = atoll(gtk_label_get_text((GtkLabel *)book_master_update->label_code2));
	
	/*Open file*/
	fp1 = fopen("Addbook.txt", "r+w");
	
	//strcpy(group_file, "data/");
	strcat(group_file, sem);
	strcat(group_file, "Addbook.txt");
	fp2 = fopen(group_file, "r+w");
	
	g_print("Inside Item Master write update.\n");
	
	while(fread(&code1, sizeof(long long int), 1, fp1)){
		g_print("Code : %lld\n", code1);
		
		
		fread(&ch, sizeof(char), 1, fp1);
		
		fread(&size_sem, sizeof(int), 1, fp1);
		g_print("Inside loop\n");
		sem1 = (char *)malloc(sizeof(char) * size_sem + 1);
		fread(sem1, sizeof(char), size_sem, fp1);
		sem1[size_sem] = '\0';
		g_print("Group : %s\n", sem1);
		
		fread(&size_subject, sizeof(int), 1, fp1);
		subject1 = (char *)malloc(sizeof(char) * size_subject + 1);
		fread(subject1, sizeof(char), size_subject, fp1);
		subject1[size_subject] = '\0';
		g_print("Category : %s\n", subject1);
		
		fread(&size_name, sizeof(int), 1, fp1);
		name1 = (char *)malloc(sizeof(char) * size_name + 1);
		fread(name1, sizeof(char), size_name, fp1);
		name1[size_name] = '\0';
		g_print("Name : %s\n", name1);
		
		if(code == code1){
			fwrite(&price, sizeof(float), 1, fp1);
			g_print("price : %f\n", price);
			fwrite(&edition, sizeof(int), 1, fp1);
			g_print("edition : %d\n", edition);
		}
		else{
			fread(&price1, sizeof(float), 1, fp1);
			g_print("price: %f\n", price1);
			fread(&edition1, sizeof(int), 1, fp1);
			g_print("edition : %d\n", edition1);
		}
		
		fread(&size_author, sizeof(int), 1, fp1);
		author1 = (char *)malloc(sizeof(char) * size_author + 1);
		fread(author1, sizeof(char), size_author, fp1);
		author1[size_author] = '\0';
		g_print("Unit : %s\n", author1);
		
	}
	
	fclose(fp1);
	fclose(fp2);
	return;
}



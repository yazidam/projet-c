#include <stdio.h>
#include <string.h>
#include "vol.h"
#include <gtk/gtk.h>
enum
{    
	REFF,
	DEST,
	NBRE,
	PRIX,
	DATE,
          COLUMNS};
//*************************************************************************************
void engvol(vol v)
{
//char type[]="vl";
//strcpy(v.type,type);
FILE*f;
f=fopen("vol.txt","a+"); 
if(f!=NULL) 
	{ 
	fprintf(f,"%s %s %s %s %s \n",v.ref,v.destination,v.nbr_place,v.prix,v.date);
	fclose(f);
	}
}
//**************************************************************************************
void afficher_vol(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter  iter;
GtkListStore *store; 
char ref[50];
char destination[50];
char nbr_place[50];
char prix[50];
char date[50];
store=NULL ;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("ref", renderer, "text", REFF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("destination", renderer, "text", DEST,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("nbr_place", renderer, "text", NBRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text", PRIX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", DATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

		store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("vol.txt","r");
	if(f==NULL)
	return;
	else
		{
		f = fopen("vol.txt","a+");
		while(fscanf(f," %s %s %s %s %s \n",ref,destination,nbr_place,prix,date)!=EOF)
			{
			//if(strcmp(type,"vl")==0)
			//{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store,&iter,REFF,ref,DEST,destination,NBRE,nbr_place,PRIX,prix,DATE,date, -1);
			//}
			}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
	}
}
//***************************************************************************************
int verif(char x[])
{
vol v ;
int nS=0;
FILE* f=fopen ("vol.txt" , "r");

if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date)!=EOF)
		{ 
		if(strcmp(v.ref,x)==0)
		nS++;
		}
	}
fclose(f);
return nS;
}
//*****************************************************************************************************************
vol CC(char ref1[])
{
vol v ;
remove("tamp.txt");
FILE* f=fopen ("vol.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date)!=EOF)
		{ 
		if (strcmp(ref1,v.ref)==0)
			{
			FILE *t=fopen("tamp.txt","a+");
			fprintf(t,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date);
			fclose(t);		
			}
		}
	}
fclose(f);
return v;
}
//********************************************************************************************************************
void supprimerm(char ref[])
{
vol v;

FILE *vv=fopen("vol.txt","r");
FILE *t=fopen("tamp2.txt","a+");
if (vv!=NULL) 
	{ 
	while(fscanf(vv,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date)!=EOF)
		{
		if (strcmp(v.ref,ref)!=0)
			{
			fprintf(t,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date);
			}
		}
	}
fclose(vv);
fclose(t);
remove("vol.txt");
rename("tamp2.txt","vol.txt");
}
//***********************************************************************************************************************
char combo1(char refs[][50])
{
int nS=0;
vol v;
FILE* f=fopen ("vol.txt" , "r");
      
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date)!=EOF)
		{ 
		//if(strcmp(v.type,"vl")==0)
		//	{
			strcpy (refs[nS],v.ref);
			nS++;
		//	}
		}	
	}
fclose(f);
return nS;
}
//****************************************************************************************************************************************
vol BB()
{
vol v ;
FILE* f=fopen ("tamp.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date)!=EOF)
		{ 
		fclose(f);
		return v;
		}
	}
}
//**************************************************************************************************************************************
void AA(vol v)
{
	char ref[50];
	char destination[50];
	char nbr_place[50];
	char prix[50];
	char date[50];

FILE *vv=fopen("vol.txt","r");
FILE *t=fopen("tamp1.txt","a+");
if (vv!=NULL) 
	{ 
	while(fscanf(vv,"%s %s %s %s %s\n",ref,destination,nbr_place,prix,date)!=EOF)
		{
		if (strcmp(ref,v.ref)!=0)
		fprintf(t,"%s %s %s %s %s\n",ref,destination,nbr_place,prix,date);
		else 
		fprintf(t,"%s %s %s %s %s\n",v.ref,v.destination,v.nbr_place,v.prix,v.date);
		}
	}
fclose(vv);
fclose(t);
remove("vol.txt");
rename("tamp1.txt","vol.txt");
}

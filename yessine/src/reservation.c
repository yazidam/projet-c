#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"
#include <gtk/gtk.h>
enum
{    
	REFF,
	DEST,
	NBRE,
	PRIX,
	DATE,
          COLUMNS};
int vol_diponible(char tab[50][50],char des[50])
{
int i,nS=0;

FILE* f=fopen ("vol.txt" , "r");
char ref[50];
char destination[50];
int nbr_places;
int prix;
char date[50];
if (f!=NULL) 
{ 
  while (fscanf(f,"%s %s %d %d %s\n",ref,destination,&nbr_places,&prix,date)!=EOF)
   { 
     if ((strcmp(destination,des))==0)
      { 
               strcpy(tab[nS],date);
               nS++;
      }
   }
}
fclose(f);
return nS;
}
int place_dispo_vol(char des[50])
{
int i,ns=0;
FILE* f=fopen ("vol.txt" , "r");
char ref[50];
char destination[50];
int nbr_places;
int prix;
char date[50];
if (f!=NULL) 
{ 
  while (fscanf(f,"%s %s %d %d %s\n",ref,destination,&nbr_places,&prix,date)!=EOF)
   { 
     if ((strcmp(date,des))==0)
      { 
            ns = nbr_places;
		
      }
   }
}
fclose(f);
return ns;
}
int vol_prix(char des[50])
{
int i,ns=0;
FILE* f=fopen ("vol.txt" , "r");
char ref[50];
char destination[50];
int nbr_places;
int prix;
char date[50];
if (f!=NULL) 
{ 
  while (fscanf(f,"%s %s %d %d %s\n",ref,destination,&nbr_places,&prix,date)!=EOF)
   {
     if ((strcmp(date,des))==0)
      { 
            ns = prix;
		
      }
   }
}
fclose(f);
return ns;
}
void save(char des[50],char Date[50],int nbr,int prix)
{
int i,ns=0;
char cin[50];
char nom[50];
char prenom[50];
char Ref[50];
char ref[50];
char destination[50];
int nbr_places;
int Prix;
char date[50];


FILE* f=fopen ("vol.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %d %d %s\n",ref,destination,&nbr_places,&Prix,date)!=EOF)
		{ 
		if ((strcmp(date,Date))==0)
			{ 
			strcpy(Ref,ref);
			}
		}
fclose(f);
}


FILE* x=fopen ("cl_en_ligne.txt" , "r");
fscanf(x,"%s %s %s",cin,prenom,nom);
FILE* l=fopen("v_res.txt","a");
	if (l!=NULL) 
		{ 
		fprintf(l,"%s %s %s %s %s %s %d %d\n",cin,nom,prenom,des,Date,Ref,prix,nbr);
		}
fclose(l);
fclose(x);
}
int place_res_vol(char des[50])
{
int i,ns=0;
char cin[50];
char nom[50];
char prenom[50];
char Ref[50];
char ref[50];
char destination[50];
int nbr_places;
int prix,nbr;;
char date[50];
FILE* f=fopen ("vol.txt" , "r");


if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %d %d %s\n",ref,destination,&nbr_places,&prix,date)!=EOF)
		{ 
		if ((strcmp(date,des))==0)
		strcpy(Ref,ref);
		}
	}
fclose(f);
FILE* l=fopen("v_res.txt","r");
if (l!=NULL) 
	{ 
	while (fscanf(l,"%s %s %s %s %s %s %d %d\n",cin,nom,prenom,des,date,ref,&prix,&nbr)!=EOF)
		{ 
		if ((strcmp(Ref,ref))==0)
		ns+=nbr;	
		}
	}
fclose(l);
return ns;
}
//**************************************************************************
date jr_s(date x)
{
int jourx;
if((x.mois==1)||(x.mois==3)||(x.mois==5)||(x.mois==7)||(x.mois==8)||(x.mois==10)||(x.mois==12));
jourx=31;
if((x.mois==4)||(x.mois==6)||(x.mois==9)||(x.mois==11));
jourx=30;
if(x.mois==2);
jourx=28;
x.jour++;
if(x.jour>jourx)
	{
	x.mois++;
	x.jour=1;
	if(x.mois>12)
		{
		x.mois=1;
		x.annee++;
		}
	}
return x;
}

//*******************
int verif_d(date x,char Ref[50])
{
char ref[50];
char mark[50];
int prix;
date y;
FILE* f=fopen ("voiture.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %d %d %d %d\n",ref,mark,&prix,&y.jour,&y.mois,&y.annee)!=EOF)
		{ 
		if ((x.jour==y.jour)&&(x.mois==y.mois)&&(x.annee==y.annee)&&(strcmp(ref,Ref))==0)
		return 0;
		}
	}
fclose(f);
return -1;
}
//******************
int verif_r(date x,char Ref[50])
{
char cin[50];
char prenom[50];
char nom[50];
char ref[50];
char mark[50];
int prix,duree;
date y;
int ns=0;
FILE* f=fopen ("res_voiture.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %d %d %d %d\n",cin,prenom,nom,ref,mark,&prix,&y.jour,&y.mois,&y.annee)!=EOF)
		{ 
		if ((x.jour==y.jour)&&(x.mois==y.mois)&&(x.annee==y.annee)&&(strcmp(ref,Ref))==0)
		ns++;;
		}
	}
fclose(f);
return ns;
}

int voiture_diponible(char tab[50][50],char Mark[50])
{
int i,j,nS=0;
FILE* f=fopen ("voiture.txt" , "r");
char ref[50];
char destination[50];
int nbr_places;
int prix;
char mark[50];
date y;
if (f!=NULL) 
{ 
  while (fscanf(f,"%s %s %d %d %d %d\n",ref,mark,&prix,&y.jour,&y.mois,&y.annee)!=EOF)
   { 
     if ((strcmp(Mark,mark))==0)	
      { 
		for(i=0,j=0;i<nS;i++)
		if(strcmp(tab[i],ref)==0)
		j++;
		if(j==0){
               strcpy(tab[nS],ref);
               nS++;}
      }
   }
}
fclose(f);
return nS;
}
//******************************************
int voiture_prix(char Ref[50])
{
int i,nS=0;
FILE* f=fopen ("voiture.txt" , "r");
char ref[50];
char destination[50];
int nbr_places;
int prix;
char mark[50];
date y;
if (f!=NULL) 
{ 
  while (fscanf(f,"%s %s %d %d %d %d\n",ref,mark,&prix,&y.jour,&y.mois,&y.annee)!=EOF)
   { 
     if ((strcmp(Ref,ref))==0)
      { 
               nS=prix;
      }
   }
}
fclose(f);
return nS;
}

//***************************
void save_voiture(char ref[50],char mark[50],int duree,int prix,date y)
{
int i,ns=0;
char cin[50];
char nom[50];
char prenom[50];

FILE* x=fopen ("cl_en_ligne.txt" , "r");
fscanf(x,"%s %s %s",cin,prenom,nom);
FILE* l=fopen("res_voiture.txt","a");
	if (l!=NULL) 
		{ 
		fprintf(l,"%s %s %s %s %s %d %d %d %d\n",cin,prenom,nom,ref,mark,(prix/duree),y.jour,y.mois,y.annee);
		}
fclose(l);
fclose(x);
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
char type[50];
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
		while(fscanf(f," %s %s %s %s %s %s\n",ref,destination,nbr_place,prix,date,type)!=EOF)
			{
			if(strcmp(type,"vl")==0)
			{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store,&iter,REFF,ref,DEST,destination,NBRE,nbr_place,PRIX,prix,DATE,date, -1);
			}
			}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
	}
}

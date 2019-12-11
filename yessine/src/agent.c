#include <stdio.h>
#include <string.h>
#include "agent.h"
#include <gtk/gtk.h>
enum
{    
	CIN,
	NOM,
	PRENOM,
	DATE,
	MDP,
	ADRESSE,
	GSM,
          COLUMNS};
//*******************************************
void ajouter(Personne p)//iscri cl
{
char type[]="cl";
strcpy(p.type,type);
FILE*f;
f=fopen("agent.txt","a+"); 
if(f!=NULL) 
	{ 
	fprintf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type);
	fclose(f);
	}
}

//***************************************
void ajouter_ag(Personne p)
{
char type[]="ag";
strcpy(p.type,type);
FILE*f;
f=fopen("agent.txt","a+"); 
if(f!=NULL) 
	{ 
	fprintf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type);
	fclose(f);
	}
}
//********************************************************************
void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter  iter;
GtkListStore *store; 
char cin[50];
char nom[50];
char prenom[50];
char date_naissance[50];
char mot_de_passe[50];
char adresse[50];
char gsm[50];
char type[50];
store=NULL ;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("date_naissance", renderer, "text", DATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("mot_de_passe", renderer, "text", MDP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text", ADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("gsm", renderer, "text", GSM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("agent.txt","r");
	if(f==NULL)
	return;
	else
		{
		f = fopen("agent.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,date_naissance,gsm,mot_de_passe,adresse,type)!=EOF)
			{
			if(strcmp(type,"ag")==0)
			{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,DATE,date_naissance,GSM,gsm,MDP,mot_de_passe,ADRESSE,adresse, -1);
			}
			}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
	}
}
//*********************************************************************************************
void afficher_personne_cl(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter  iter;
GtkListStore *store; 
char cin[50];
char nom[50];
char prenom[50];
char date_naissance[50];
char mot_de_passe[50];
char adresse[50];
char gsm[50];
char type[50];
store=NULL ;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("date_naissance", renderer, "text", DATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("mot_de_passe", renderer, "text", MDP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text", ADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("gsm", renderer, "text", GSM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("agent.txt","r");
	if(f==NULL)
	return;
	else
		{
		f = fopen("agent.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,date_naissance,gsm,mot_de_passe,adresse,type)!=EOF)
			{
			if(strcmp(type,"cl")==0)
			{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,DATE,date_naissance,GSM,gsm,MDP,mot_de_passe,ADRESSE,adresse, -1);
			}
			}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
	}
}
//*******************************************
int combo1(char cins[][50])
{
int nS=0;
Personne p;
FILE* f=fopen ("agent.txt" , "r");
      
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type)!=EOF)
		{ 
		if(strcmp(p.type,"ag")==0)
			{
			strcpy (cins[nS],p.cin);
			nS++;
			}
		}	
	}
fclose(f);
return nS;
}
//********************************************
int combo2(char cins[][50])
{
int nS=0;
Personne p;
FILE* f=fopen ("agent.txt" , "r");
      
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type)!=EOF)
		{ 
		if(strcmp(p.type,"cl")==0)
			{
			strcpy (cins[nS],p.cin);
			nS++;
			}
		}	
	}
fclose(f);
return nS;
}
//***********************************************
void supprimerm(char cin[])
{
Personne p;

FILE *l=fopen("agent.txt","r");
FILE *t=fopen("tamp2.txt","a+");
if (l!=NULL) 
	{ 
	while(fscanf(l,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type)!=EOF)
		{
		if (strcmp(p.cin,cin)!=0)
			{
			fprintf(t,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type);
			}
		}
	}
fclose(l);
fclose(t);
remove("agent.txt");
rename("tamp2.txt","agent.txt");
}
//************************
int verif(char x[])
{
Personne p ;
int nS=0;
FILE* f=fopen ("agent.txt" , "r");

if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type)!=EOF)
		{ 
		if(strcmp(p.cin,x)==0)
		nS++;
		}
	}
fclose(f);
return nS;
}
//******************************************
Personne XX(char cin1[])
{
Personne p ;
FILE* f=fopen ("agent.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type)!=EOF)
		{ 
		if (strcmp(cin1,p.cin)==0)
			{
			FILE *t=fopen("tamp.txt","a+");
			fprintf(t,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type);
			fclose(t);		
			}
		}
	}
fclose(f);
return p;
}
//********************************************
Personne YY()
{
Personne p ;
FILE* f=fopen ("tamp.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type)!=EOF)
		{ 
		fclose(f);
		return p;
		}
	}
}
//***********************************************
void ZZ(Personne p)
{
	char cin[50];
	char nom[50];
	char prenom[50];
	char date_naissance[50];
	char mot_de_passe[50];
	char adresse[50];
	char gsm[50];
	char type[50];

FILE *l=fopen("agent.txt","r");
FILE *t=fopen("tamp1.txt","a+");
if (l!=NULL) 
	{ 
	while(fscanf(l,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,date_naissance,gsm,mot_de_passe,adresse,type)!=EOF)
		{
		if (strcmp(cin,p.cin)!=0)
		fprintf(t,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,date_naissance,gsm,mot_de_passe,adresse,type);
		else 
		fprintf(t,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type);
		}
	}
fclose(l);
fclose(t);
remove("agent.txt");
rename("tamp1.txt","agent.txt");
}
//**********************************************************
void cel(char cin[50],char prenom[50],char nom[50])
{
remove("cl_en_ligne.txt");
FILE *f=fopen("cl_en_ligne.txt","a+");
if (f!=NULL) 
fprintf(f,"%s %s %s\n",cin,prenom,nom);
fclose(f);
}

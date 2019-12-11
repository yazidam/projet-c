#include <gtk/gtk.h>
typedef struct 
{
int jour;
int mois;
int annee;
}date;
typedef struct
{
char ref[50];
char destination[50];
int nbr_places;
int prix;
char date[50];
}vol;
typedef struct
{
char ref[50];
char mark[50];
int prix;
date Date;
}voiture;
int vol_diponible(char tab[50][50],char des[50]);
int vol_prix(char des[50]);
int place_dispo_vol(char des[50]);
int place_res_vol(char des[50]);
void save(char des[50],char date[50],int nbr,int Prix);
date jr_s(date x);
int verif_d(date x,char Ref[50]);
int verif_r(date x,char Ref[50]);
int voiture_diponible(char tab[50][50],char Mark[50]);
int voiture_prix(char Ref[50]);
void save_voiture(char ref[50],char mark[50],int duree,int prix,date y);
void afficher_vol(GtkWidget *liste);

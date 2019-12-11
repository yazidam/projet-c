#include <gtk/gtk.h>

typedef struct
{
char cin[50];
char nom[50];
char prenom[50];
char date_naissance[50];
char mot_de_passe[50];
char adresse[50];
char gsm[50];
char type[50];
}Personne;





void ajouter(Personne p);
void ajouter_ag(Personne p);
void afficher_personne(GtkWidget *liste);
void afficher_personne_cl(GtkWidget *liste);
Personne XX(char cin1[]);
Personne YY();
void ZZ(Personne p);
int combo1(char cins[][50]);
int combo2(char cins[][50]);
void supprimerm(char cin[]);
void cel(char cin[50],char prenom[50],char nom[50]);

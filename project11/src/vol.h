#include <gtk/gtk.h>
typedef struct
{
char ref[50];
char destination[50];
char nbr_place[50];
char prix[50];
char date[50];
//char type[50];
}vol;



void engvol(vol v);
void afficher_vol(GtkWidget *liste);
vol CC(char ref1[]);
char combo1(char refs[][50]);
void supprimerm(char ref[]);
//vol XX(char ref1[]);
vol BB();
void AA(vol v);



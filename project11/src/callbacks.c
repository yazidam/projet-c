#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vol.h"



void
on_ajvol_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *ajout_vol ;
	ajout_vol = create_ajout_vol ();
	gtk_widget_show(ajout_vol);
}


void
on_modvol_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
vol v;
char ref[50];
v = CC(ref);
GtkWidget *Combobox1;
Combobox1 = lookup_widget(objet_graphique,"combobox1");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1))!= NULL)
	{
	strcpy(ref,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
	CC(ref);
	GtkWidget *modif_vol ;
	modif_vol = create_modif_vol ();
	gtk_widget_show(modif_vol);
	}
}


void
on_supvol_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char ref[50];
GtkWidget *Combobox1;
Combobox1 = lookup_widget(objet_graphique,"combobox1");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1))!= NULL)
	{
	strcpy(ref , gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
	supprimerm(ref);
	}
}


void
on_rechvol_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
int n,i;
char refs[50][50];
GtkWidget *Combobox1;
Combobox1=lookup_widget(objet_graphique,"combobox1");
n=combo1(refs); 

for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox1),_(refs[i]));
}
}


void
on_refvol_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_vol;
espace_vol=lookup_widget(button,"espace_vol");
gtk_widget_hide(espace_vol);
espace_vol = create_espace_vol ();
gtk_widget_show (espace_vol);
GtkWidget *treeview1;
treeview1=lookup_widget(espace_vol,"treeview1");
afficher_vol(treeview1);
}


void
on_engvol_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
int x;
GtkWidget	*input_ref	=	lookup_widget(objet,"entry5");
GtkWidget	*input_destination	=	lookup_widget(objet,"entry6");
GtkWidget	*input_nbr	=	lookup_widget(objet,"spinbutton1");
GtkWidget	*input_prix	=	lookup_widget(objet,"entry1");
GtkWidget	*input_date	=	lookup_widget(objet,"entry4");
GtkWidget	*input_cref	=	lookup_widget(objet,"entry7");
/*GtkWidget	*input_mdp	=	lookup_widget(objet,"entry027");
GtkWidget	*input_cmdp	=	lookup_widget(objet,"entry028");*/
vol v;
char cref[50];
strcpy(v.ref,gtk_entry_get_text(GTK_ENTRY(input_ref)));
strcpy(v.destination,gtk_entry_get_text(GTK_ENTRY(input_destination)));
strcpy(v.nbr_place,gtk_entry_get_text(GTK_ENTRY(input_nbr)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input_prix)));
strcpy(v.date,gtk_entry_get_text(GTK_ENTRY(input_date)));
/*strcpy(p.date_naissance,gtk_entry_get_text(GTK_ENTRY(input_date)));
strcpy(p.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_mdp)));*/
strcpy(cref,gtk_entry_get_text(GTK_ENTRY(input_cref)));
x=verif(v.ref);
if (x==0)
	{
		if(strcmp(cref,v.ref)==0)
			{
			engvol(v);
			GtkWidget *ajout_vol;
			ajout_vol=lookup_widget(objet,"ajout_vol");
			gtk_widget_hide(ajout_vol);
			}
		else
			{
			GtkWidget *output5=lookup_widget(objet,"label14");
			gtk_label_set_text(GTK_LABEL(output5),"verifier referance");
			}
	}
else
	{
	GtkWidget *output5=lookup_widget(objet,"label14");
	gtk_label_set_text(GTK_LABEL(output5),"verifier votre referance");
	}

			
}


void
on_retesvol_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_save_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
vol v;
int x;
v=BB();
GtkWidget	*input_reff	=	lookup_widget(button,"entry8");
GtkWidget	*input_dest	=	lookup_widget(button,"entry9");
GtkWidget	*input_nbre	=	lookup_widget(button,"spinbutton2");
GtkWidget	*input_prix	=	lookup_widget(button,"entry10");
GtkWidget	*input_date	=	lookup_widget(button,"entry11");
GtkWidget	*input_cref	=	lookup_widget(button,"entry12");
//GtkWidget	*input_mdp	=	lookup_widget(button,"entry037");
//GtkWidget	*input_cmdp	=	lookup_widget(button,"entry038");
char cref[50];
strcpy(v.ref,gtk_entry_get_text(GTK_ENTRY(input_reff)));
strcpy(v.destination,gtk_entry_get_text(GTK_ENTRY(input_dest)));
strcpy(v.nbr_place,gtk_entry_get_text(GTK_ENTRY(input_nbre)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input_prix)));
strcpy(v.date,gtk_entry_get_text(GTK_ENTRY(input_date)));
//strcpy(v.type,"vl");
//strcpy(v.date_naissance,gtk_entry_get_text(GTK_ENTRY(input_date)));
//strcpy(v.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_mdp)));
strcpy(cref,gtk_entry_get_text(GTK_ENTRY(input_cref)));
if(strcmp(cref,v.ref)==0)
	{
	AA(v);
	remove("tamp.txt");
	GtkWidget *modif_vol;
	modif_vol=lookup_widget(button,"modif_vol");
	gtk_widget_hide(modif_vol);
	}
else
	{
	GtkWidget *output5=lookup_widget(button,"label22");
	gtk_label_set_text(GTK_LABEL(output5),"confirmer votre referance");
	}
}


void
on_modif_vol_show                      (GtkWidget       *widget,
                                        gpointer         user_data)
{
vol v;
v=BB();
GtkWidget	*input_reff	=	lookup_widget(widget,"entry8");
GtkWidget	*input_dest	=	lookup_widget(widget,"entry9");
GtkWidget	*input_nbr	=	lookup_widget(widget,"spinbutton2");
GtkWidget	*input_prix	=	lookup_widget(widget,"entry10");
GtkWidget	*input_date	=	lookup_widget(widget,"entry11");
GtkWidget	*input_ref	=	lookup_widget(widget,"entry12");
//GtkWidget	*input_mdp	=	lookup_widget(widget,"entry037");
//GtkWidget	*input_cmdp	=	lookup_widget(widget,"entry038");
gtk_entry_set_text (GTK_ENTRY (input_reff), _(v.ref));
gtk_entry_set_text (GTK_ENTRY (input_dest), _(v.destination));
gtk_entry_set_text (GTK_ENTRY (input_nbr), _(v.nbr_place));
gtk_entry_set_text (GTK_ENTRY (input_prix), _(v.prix));
gtk_entry_set_text (GTK_ENTRY (input_date), _(v.date));
gtk_entry_set_text (GTK_ENTRY (input_reff), _(v.ref));
//gtk_entry_set_text (GTK_ENTRY (input_mdp), _(p.mot_de_passe));
//gtk_entry_set_text (GTK_ENTRY (input_cmdp), _(p.mot_de_passe));
}


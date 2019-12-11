#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"
#include "reservation.h"
void
on_login1_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inputlogin;
GtkWidget *inputpasswd;
GtkWidget *espace_agent;
GtkWidget *welcome;
GtkWidget *output;
GtkWidget *espace_client;
GtkWidget *espace_admin;
Personne p;
char cin[50];
char mot_de_passe[50];
int x=0;
welcome=lookup_widget(button,"welcome");
inputlogin=lookup_widget(button,"entry1");
inputpasswd=lookup_widget(button,"entry2");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(inputlogin)));
strcpy(mot_de_passe,gtk_entry_get_text(GTK_ENTRY(inputpasswd)));

FILE *f;
f=fopen("agent.txt","r");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.date_naissance,p.gsm,p.mot_de_passe,p.adresse,p.type)!=EOF)
{
	if(strcmp(p.cin,cin)==0)
		if (strcmp(p.mot_de_passe,mot_de_passe)==0)
			if (strcmp(p.type,"ag")==0)
			{
			gtk_widget_hide(welcome);
			espace_agent=create_espace_agent();
			gtk_widget_show(espace_agent);
			x=1;
			break;
			}	
			else if (strcmp(p.type,"ad")==0)	
			{
			gtk_widget_hide(welcome);
			espace_admin=create_espace_admin();
			gtk_widget_show(espace_admin);
			GtkWidget *treeview1;
			treeview1=lookup_widget(espace_admin,"treeview1");
			afficher_personne(treeview1);
			GtkWidget *treeview2;
			treeview2=lookup_widget(espace_admin,"treeview2");
			afficher_personne_cl(treeview2);			
			x=1;
			
			break;
			}
			else if (strcmp(p.type,"cl")==0)
			{
			gtk_widget_hide(welcome);
			espace_client=create_espace_client();
			gtk_widget_show(espace_client);
			cel(p.cin,p.prenom,p.nom);
			GtkWidget *treeview100;
			treeview100=lookup_widget(espace_client,"treeview100");
			afficher_vol(treeview100);
			x=1;
			
			break;
			}	
}fclose(f);
}

if (x == 0)
{output=lookup_widget(button,"label5");
gtk_label_set_text(GTK_LABEL(output),"error");
}
}

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
int x;
GtkWidget	*input_nom	=	lookup_widget(button,"entry001");
GtkWidget	*input_prenom	=	lookup_widget(button,"entry002");
GtkWidget	*input_cin	=	lookup_widget(button,"entry003");
GtkWidget	*input_gsm	=	lookup_widget(button,"entry004");
GtkWidget	*input_adresse	=	lookup_widget(button,"entry005");
GtkWidget	*input_date	=	lookup_widget(button,"entry006");
GtkWidget	*input_mdp	=	lookup_widget(button,"entry007");
GtkWidget	*input_cmdp	=	lookup_widget(button,"entry008");
Personne p;
char cmdp[50];
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input_cin)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input_gsm)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input_adresse)));
strcpy(p.date_naissance,gtk_entry_get_text(GTK_ENTRY(input_date)));
strcpy(p.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_mdp)));
strcpy(cmdp,gtk_entry_get_text(GTK_ENTRY(input_cmdp)));
x=verif(p.cin);
if (x==0)
	{
		if(strcmp(cmdp,p.mot_de_passe)==0)
			{
			ajouter(p);
			GtkWidget *validation;
			validation = create_validation ();
			gtk_widget_show (validation);
			}
		else
			{
			GtkWidget *output5=lookup_widget(button,"label00");
			gtk_label_set_text(GTK_LABEL(output5),"verifier mot de passe");
			}
	}
else
	{
	GtkWidget *output5=lookup_widget(button,"label00");
	gtk_label_set_text(GTK_LABEL(output5),"changer cin");
	}
}

void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *welcome ;

welcome = create_welcome();
gtk_widget_show (welcome);

espace_admin=lookup_widget(button,"espace_admin");
gtk_widget_hide(espace_admin);

}

void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_agent;
GtkWidget *welcome ;

welcome = create_welcome ();
gtk_widget_show (welcome);

espace_agent=lookup_widget(button,"espace_agent");
gtk_widget_hide(espace_agent);
}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_client;
GtkWidget *welcome ;

welcome = create_welcome ();
gtk_widget_show (welcome);

espace_client=lookup_widget(button,"espace_client");
gtk_widget_hide(espace_client);
}


void
on_modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[50];
GtkWidget *Combobox1;
Combobox1 = lookup_widget(objet_graphique,"combobox1");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1))!= NULL)
	{
	strcpy(cin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
	XX(cin);
	GtkWidget *modif_ag ;
	modif_ag = create_modif_ag ();
	gtk_widget_show(modif_ag);
	}
}

void
on_supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[50];
GtkWidget *Combobox1;
Combobox1 = lookup_widget(objet_graphique,"combobox1");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1))!= NULL)
	{
	strcpy(cin , gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
	supprimerm(cin);
	GtkWidget *validation;
	validation = create_validation ();
	gtk_widget_show (validation);
	}
}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_ag ;
ajout_ag = create_ajout_ag ();
gtk_widget_show (ajout_ag);
}


void
on_ajouter_ag_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
int x;
GtkWidget	*input_nom	=	lookup_widget(objet,"entry011");
GtkWidget	*input_prenom	=	lookup_widget(objet,"entry012");
GtkWidget	*input_cin	=	lookup_widget(objet,"entry013");
GtkWidget	*input_gsm	=	lookup_widget(objet,"entry014");
GtkWidget	*input_adresse	=	lookup_widget(objet,"entry015");
GtkWidget	*input_date	=	lookup_widget(objet,"entry016");
GtkWidget	*input_mdp	=	lookup_widget(objet,"entry017");
GtkWidget	*input_cmdp	=	lookup_widget(objet,"entry018");
Personne p;
char cmdp[50];
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input_cin)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input_gsm)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input_adresse)));
strcpy(p.date_naissance,gtk_entry_get_text(GTK_ENTRY(input_date)));
strcpy(p.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_mdp)));
strcpy(cmdp,gtk_entry_get_text(GTK_ENTRY(input_cmdp)));
x=verif(p.cin);
if (x==0)
	{
		if(strcmp(cmdp,p.mot_de_passe)==0)
			{
			ajouter_ag(p);
			GtkWidget *validation;
			validation = create_validation ();
			gtk_widget_show (validation);
			GtkWidget *ajout_ag;
			ajout_ag=lookup_widget(objet,"ajout_ag");
			gtk_widget_hide(ajout_ag);
			}
		else
			{
			GtkWidget *output5=lookup_widget(objet,"label01");
			gtk_label_set_text(GTK_LABEL(output5),"verifier mot de passe");
			}
	}
else
	{
	GtkWidget *output5=lookup_widget(objet,"label01");
	gtk_label_set_text(GTK_LABEL(output5),"changer cin");
	}
}


void
on_retour_ag_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_ag ;
ajout_ag=lookup_widget(button,"ajout_ag");
gtk_widget_hide(ajout_ag);

}


void
on_refresh_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
espace_admin=lookup_widget(button,"espace_admin");
gtk_widget_hide(espace_admin);
espace_admin = create_espace_admin ();
gtk_widget_show (espace_admin);
GtkWidget *treeview1;
treeview1=lookup_widget(espace_admin,"treeview1");
afficher_personne(treeview1);
GtkWidget *treeview2;
treeview2=lookup_widget(espace_admin,"treeview2");
afficher_personne_cl(treeview2);
}


void
on_r_cin_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int n,i;
char cins[50][50];
GtkWidget *Combobox1;
Combobox1=lookup_widget(objet_graphique,"combobox1");
n=combo1(cins); 

for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox1),_(cins[i]));
}
}


void
on_save_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
Personne p;
int x;
p=YY();
GtkWidget	*input_nom	=	lookup_widget(button,"entry021");
GtkWidget	*input_prenom	=	lookup_widget(button,"entry022");
GtkWidget	*input_cin	=	lookup_widget(button,"entry023");
GtkWidget	*input_gsm	=	lookup_widget(button,"entry024");
GtkWidget	*input_adresse	=	lookup_widget(button,"entry025");
GtkWidget	*input_date	=	lookup_widget(button,"entry026");
GtkWidget	*input_mdp	=	lookup_widget(button,"entry027");
GtkWidget	*input_cmdp	=	lookup_widget(button,"entry028");
char cmdp[50];
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input_cin)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input_gsm)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input_adresse)));
strcpy(p.date_naissance,gtk_entry_get_text(GTK_ENTRY(input_date)));
strcpy(p.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_mdp)));
strcpy(cmdp,gtk_entry_get_text(GTK_ENTRY(input_cmdp)));
if(strcmp(cmdp,p.mot_de_passe)==0)
	{
	ZZ(p);
	remove("tamp.txt");
	GtkWidget *validation;
	validation = create_validation ();
	gtk_widget_show (validation);
	GtkWidget *modif_ag;
	modif_ag=lookup_widget(button,"modif_ag");
	gtk_widget_hide(modif_ag);
	}
else
	{
	GtkWidget *output5=lookup_widget(button,"label02");
	gtk_label_set_text(GTK_LABEL(output5),"verifier mot de passe");
	}
}


void
on_retour_modif_ag_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif_ag ;
modif_ag = lookup_widget(button,"modif_ag");
gtk_widget_hide(modif_ag);
remove("tamp.txt");
}

void
on_modif_ag_show                       (GtkWidget       *widget,
                                        gpointer         user_data)
{
Personne p;
p=YY();
GtkWidget	*input_nom	=	lookup_widget(widget,"entry021");
GtkWidget	*input_prenom	=	lookup_widget(widget,"entry022");
GtkWidget	*input_cin	=	lookup_widget(widget,"entry023");
GtkWidget	*input_gsm	=	lookup_widget(widget,"entry024");
GtkWidget	*input_adresse	=	lookup_widget(widget,"entry025");
GtkWidget	*input_date	=	lookup_widget(widget,"entry026");
GtkWidget	*input_mdp	=	lookup_widget(widget,"entry027");
GtkWidget	*input_cmdp	=	lookup_widget(widget,"entry028");
gtk_entry_set_text (GTK_ENTRY (input_nom), _(p.nom));
gtk_entry_set_text (GTK_ENTRY (input_prenom), _(p.prenom));
gtk_entry_set_text (GTK_ENTRY (input_cin), _(p.cin));
gtk_entry_set_text (GTK_ENTRY (input_gsm), _(p.gsm));
gtk_entry_set_text (GTK_ENTRY (input_adresse), _(p.adresse));
gtk_entry_set_text (GTK_ENTRY (input_date), _(p.date_naissance));
gtk_entry_set_text (GTK_ENTRY (input_mdp), _(p.mot_de_passe));
gtk_entry_set_text (GTK_ENTRY (input_cmdp), _(p.mot_de_passe));
}


void
on_modifier_cl_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[50];
GtkWidget *Combobox2;
Combobox2 = lookup_widget(objet_graphique,"combobox2");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2))!= NULL)
	{
	strcpy(cin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
	XX(cin);
	GtkWidget *modif_ag ;
	modif_ag = create_modif_ag ();
	gtk_widget_show(modif_ag);
	}
}


void
on_supprimer_cl_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[50];
GtkWidget *Combobox2;
Combobox2 = lookup_widget(objet_graphique,"combobox2");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2))!= NULL)
	{
	strcpy(cin , gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
	supprimerm(cin);
	GtkWidget *validation;
	validation = create_validation ();
	gtk_widget_show (validation);
	}
}


void
on_r_cin_cl_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int n,i;
char cins[50][50];
GtkWidget *Combobox2;
Combobox2=lookup_widget(objet_graphique,"combobox2");
n=combo2(cins); 

for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox2),_(cins[i]));
}
}


void
on_refresh_cl_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
espace_admin=lookup_widget(button,"espace_admin");
gtk_widget_hide(espace_admin);
espace_admin = create_espace_admin ();
gtk_widget_show (espace_admin);
GtkWidget *treeview1;
treeview1=lookup_widget(espace_admin,"treeview1");
afficher_personne(treeview1);
GtkWidget *treeview2;
treeview2=lookup_widget(espace_admin,"treeview2");
afficher_personne_cl(treeview2);
}


void
on_ajouter_cl_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
int x;
GtkWidget	*input_nom	=	lookup_widget(objet,"entry031");
GtkWidget	*input_prenom	=	lookup_widget(objet,"entry032");
GtkWidget	*input_cin	=	lookup_widget(objet,"entry033");
GtkWidget	*input_gsm	=	lookup_widget(objet,"entry034");
GtkWidget	*input_adresse	=	lookup_widget(objet,"entry035");
GtkWidget	*input_date	=	lookup_widget(objet,"entry036");
GtkWidget	*input_mdp	=	lookup_widget(objet,"entry037");
GtkWidget	*input_cmdp	=	lookup_widget(objet,"entry038");
Personne p;
char cmdp[50];
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input_cin)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input_gsm)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input_adresse)));
strcpy(p.date_naissance,gtk_entry_get_text(GTK_ENTRY(input_date)));
strcpy(p.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_mdp)));
strcpy(cmdp,gtk_entry_get_text(GTK_ENTRY(input_cmdp)));
x=verif(p.cin);
if (x==0)
	{
		if(strcmp(cmdp,p.mot_de_passe)==0)
			{
			ajouter(p);
			GtkWidget *validation;
			validation = create_validation ();
			gtk_widget_show (validation);
			GtkWidget *ajout_cl;
			ajout_cl=lookup_widget(objet,"ajout_cl");
			gtk_widget_hide(ajout_cl);
			}
		else
			{
			GtkWidget *output5=lookup_widget(objet,"label03");
			gtk_label_set_text(GTK_LABEL(output5),"verifier mot de passe");
			}
	}
else
	{
	GtkWidget *output5=lookup_widget(objet,"label03");
	gtk_label_set_text(GTK_LABEL(output5),"changer cin");
	}
}


void
on_ajouter_cl1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_cl ;
ajout_cl = create_ajout_cl ();
gtk_widget_show (ajout_cl);
}


void
on_spinbutton101_changed               (GtkEditable     *editable,
                                        gpointer         user_data)
{
char ch[50];
int nbr,prix,n=0;
char date[50];
char des[50];
char Prix[50];
GtkWidget *Combobox102;
Combobox102=lookup_widget(editable,"combobox102");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102)));
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102))!=NULL)
{
GtkWidget *spin;
spin=lookup_widget(editable,"spinbutton101");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

n=vol_prix(des);
n=n*nbr;
sprintf(ch,"%d",n);
GtkWidget	*input1	=	lookup_widget(editable,"entry102");
gtk_entry_set_text (GTK_ENTRY (input1),_(ch));
}
}


void
on_combobox102_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
char ch[50];
int i,nbr,n=0;
char date[50];
char des[50];
GtkWidget *spin;
spin=lookup_widget(combobox,"spinbutton101");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));
GtkWidget *Combobox102;
Combobox102=lookup_widget(combobox,"combobox102");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102)));
n=place_dispo_vol(des);
n-=place_res_vol(des);
sprintf(ch,"%d",n);
GtkWidget	*input	=	lookup_widget(combobox,"entry101");
gtk_entry_set_text (GTK_ENTRY (input),_(ch));
}


void
on_combobox101_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
int i,n;
char tab[50][50];
char des[50];
GtkWidget *Combobox101;
Combobox101=lookup_widget(combobox,"combobox101");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox101)));
GtkWidget *Combobox102;
Combobox102=lookup_widget(combobox,"combobox102");
n=vol_diponible(tab,des);
for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox102),_(tab[i]));
}
}


void
on_reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char des[50],date[50],Prix[50],Nbr1[50];
int nbr,prix,nbr1;
GtkWidget *Combobox101;
Combobox101=lookup_widget(button,"combobox101");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox101)));
GtkWidget *Combobox102;
Combobox102=lookup_widget(button,"combobox102");
strcpy(date,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102)));

GtkWidget *spin;
spin=lookup_widget(button,"spinbutton101");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

GtkWidget	*input1	=	lookup_widget(button,"entry102");
strcpy(Prix,gtk_entry_get_text(GTK_ENTRY(input1)));
prix=atoi(Prix);
GtkWidget	*input	=	lookup_widget(button,"entry101");
strcpy(Nbr1,gtk_entry_get_text(GTK_ENTRY(input)));
nbr1=atoi(Nbr1);
if(nbr<=nbr1)
save(des,date,nbr,prix);
else
	{
	GtkWidget *output=lookup_widget(button,"label106");
	strcat(Nbr1," places sont disponible pas plus");
	gtk_label_set_text(GTK_LABEL(output),Nbr1);
	}
}


void
on_spinbutton204_changed               (GtkEditable     *editable,
                                        gpointer         user_data)
{
char ch[50];
int nbr,prix,n=0;
char date[50];
char ref[50];
char Prix[50];
GtkWidget *Combobox202;
Combobox202=lookup_widget(editable,"combobox202");
strcpy(ref,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox202)));
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox202))!=NULL)
{
GtkWidget *spin;
spin=lookup_widget(editable,"spinbutton204");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

n=voiture_prix(ref);
n=n*nbr;
sprintf(ch,"%d",n);
GtkWidget	*input1	=	lookup_widget(editable,"entry201");
gtk_entry_set_text (GTK_ENTRY (input1),_(ch));
}
}


void
on_combobox201_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
int i,n;
char tab[50][50];
char mark[50];
GtkWidget *Combobox201;
Combobox201=lookup_widget(combobox,"combobox201");
strcpy(mark,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox201)));
GtkWidget *Combobox202;
Combobox202=lookup_widget(combobox,"combobox202");
n=voiture_diponible(tab,mark);
for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox202),_(tab[i]));
}
}


void
on_button201_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char mark[50],ref[50],Prix[50],Nbr1[50];
int nbr,prix,nbr1;
date x,y;
GtkWidget *Combobox201;
Combobox201=lookup_widget(button,"combobox201");
strcpy(mark,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox201)));
GtkWidget *Combobox202;
Combobox202=lookup_widget(button,"combobox202");
strcpy(ref,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox202)));

GtkWidget *spin;
spin=lookup_widget(button,"spinbutton204");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

GtkWidget *spin1;
spin1=lookup_widget(button,"spinbutton201");
x.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin1));
GtkWidget *spin2;
spin2=lookup_widget(button,"spinbutton202");
x.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin2));
GtkWidget *spin3;
spin3=lookup_widget(button,"spinbutton203");
x.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin3));

GtkWidget	*input	=	lookup_widget(button,"entry201");
strcpy(Nbr1,gtk_entry_get_text(GTK_ENTRY(input)));
nbr1=atoi(Nbr1);
int i=0;
int ns=0;
char ch[50];
y=x;
for(i=0;i<nbr;i++)
	{
	sprintf(ch,"voiture non disponible le %d/%d/%d",x.jour,x.mois,x.annee);
	int n=0;
	int r=0;
	n= verif_d(x,ref);
	if(n==0)
		{
		r= verif_r(x,ref);
		if(r!=0)
			{
			GtkWidget *output=lookup_widget(button,"label209");
			gtk_label_set_text(GTK_LABEL(output),ch);
			ns++;
			}
		}
	else
		{
		GtkWidget *output=lookup_widget(button,"label209");
		gtk_label_set_text(GTK_LABEL(output),ch);
		ns++;
		}
	x=jr_s(x);
	}
if(ns==0)
for(i=0;i<nbr;i++)
	{
	save_voiture(ref,mark,nbr,nbr1,y);
	GtkWidget *output=lookup_widget(button,"label209");
	gtk_label_set_text(GTK_LABEL(output),"reservation terminer");	
	x=jr_s(x);
	}
}


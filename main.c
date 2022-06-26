#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define ESC 27

void menu_principale();
void intro();
void cadre();

void menu_etudient();
void gestionaire_Etudient();
int choix_Etudient();
void Ajouter_Etudient();
int chercher_code(int id);
int chercher_Etudient(int id);
void modification_Etudient( );
void consulter_Etudient();
void supprimer_Etudient();

void menu_ouvrage();
void gestionaire_ouvrage();
int choix_ouvrage();
void nouveau_ouvrage();
int chercher_ouvrage(int id);
void consulter_ouvrage();
void supprimer_ouvrage();
void modifier_ouvrage();

void menu_pret();
void gestionaire_pret();
int choix_pret();
void nouveau_pret();
int duree(int j1,int m1,int j2,int m2);
int chercher_pret(int id);
int chercher_ne(int id);
int chercher_no(int id);
void consulter_pret();
void supprimer_pret();
void modifier_pret();

void generation_pret();
void pret_encour();


typedef struct {
int numero ;
char Nom [60] ;
int code;
char filliere [20];
int Tel;
int Annee_inscrit ;
} Etudient;
Etudient list[100];

typedef struct {
    int numero;
    int annee;
    char titre[60];
    char auteur[25];
    char specialite[20];
} ouvrage;
ouvrage livre[100];

typedef struct{
     int numero;
     int ne;
     int no;
     int jour1;
     int mois1;
     int ann1;
     int jour2;
     int mois2;
     int ann2;
     int duree;
 }pret1;
 pret1 pret[100];

 void main()
 {
          int choix;
    system("COLOR e1");
    intro();getch();
    menu_principale();
}
void menu_principale(){
    int choix;
        system("cls");
    textbackground(BLUE);textcolor(LIGHTGREEN);
    gotoxy(40,7);cprintf("                                           ");
    gotoxy(40,8);cprintf("   GESTION DE BIBLIOTHEQUE UNIVERSITAIRE   ");
    gotoxy(40,9);cprintf("                                           ");
    gotoxy(40,11);cprintf("                                           ");
    gotoxy(40,12);cprintf("         1-GESTION DES ETUDIANTS           ");
    gotoxy(40,13);cprintf("                                           ");
    gotoxy(40,14);cprintf("         2-GESTION DES OUVRAGES            ");
    gotoxy(40,15);cprintf("                                           ");
    gotoxy(40,16);cprintf("         3-GESTION DES PRETS               ");
    gotoxy(40,17);cprintf("                                           ");
    gotoxy(40,18);cprintf("         4-GENERATION D'ETATS              ");
    gotoxy(40,19);cprintf("                                           ");
    gotoxy(40,20);cprintf("         5-QUITTER                         ");
    gotoxy(40,21);cprintf("                                           ");
        do{
    gotoxy(40,23);cprintf("  Entree votre choix :                     ");
    gotoxy(70,23);cscanf("%d",&choix);}
    while(choix!=1&&choix!=2&&choix!=3&&choix!=4&&choix!=5);
    switch(choix){
        case 1: system("cls"); menu_etudient();break;
        case 2: system("cls");menu_ouvrage();break;
        case 3: system("cls");menu_pret();break;
        case 4: system("cls");generation_pret();break;
        case 5: system("cls");printf("quitter");break;
    }

}
void intro()
{
           int i,j;
    system("cls");
    textbackground(CYAN);textcolor(WHITE);
    gotoxy(25,5);cprintf("  *                         BIBLIOTHEQUE                          *   ");
    gotoxy(25,6);printf("  * **********   ********** *             ");
    gotoxy(25,7);printf("  *                               *                               *             ");
    gotoxy(25,8);printf("  *                               *                               *             ");
    gotoxy(25,9);printf("  *                               *                               *             ");
    gotoxy(25,10);printf("  *                               *                               *             ");
    gotoxy(25,11);printf("  *         READ  TO              *        faculte des            *             ");
    gotoxy(25,12);printf("  *                               *                               *             ");
    gotoxy(25,13);printf("  *            GROW               *          sciences             *             ");
    gotoxy(25,14);printf("  *                               *                               *             ");
    gotoxy(25,15);printf("  *         YOUR MIND             *        ben m'sik              *             ");
    gotoxy(25,16);printf("  *                               *                               *             ");
    gotoxy(25,17);printf("  *                               *                               *             ");
    gotoxy(25,18);printf("  *                               *                               *             ");
    gotoxy(25,19);printf("  * **********   ********** *             ");

                         for(j=0;j<=68;j++)
                            {
                                gotoxy(25+j,4);printf("\304");
                            }
                      gotoxy(24,4);printf("\332");

                      for(j=0;j<=15;j++)
                            {
                              gotoxy(24,5+j);printf("\263");
                            }
                      gotoxy(24,20);printf("\300");

                      for(j=0;j<=68;j++)
                            {
                              gotoxy(25+j,20);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=15;j++)
                            {
                              gotoxy(94,19-j);printf("\263");
                            }
                        gotoxy(94,4);printf("\277");
            textbackground(CYAN);textcolor(WHITE);
                        gotoxy(40,22);cprintf("  Appuyez sur une touche pour continue...  ");
            {getch();system("cls");}

}
 void cadre()
 {
     int j;
                              for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                      gotoxy(22,5);printf("\332");

                      for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                      gotoxy(22,28);printf("\300");

                      for(j=0;j<=89;j++)
                            {
                              gotoxy(23+j,28);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                        gotoxy(113,5);printf("\277");
                                                        for(j=0;j<=74;j++)
                            {
                                gotoxy(30+j,8);printf("\304");
                            }
                      gotoxy(29,8);printf("\332");

                      for(j=0;j<=14;j++)
                            {
                              gotoxy(29,9+j);printf("\263");
                            }
                      gotoxy(29,24);printf("\300");

                      for(j=0;j<=74;j++)
                            {
                              gotoxy(30+j,24);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=14;j++)
                            {
                              gotoxy(105,23-j);printf("\263");
                            }
                        gotoxy(105,8);printf("\277");

}
 void menu_etudient()
{
    system("cls");
    cadre();
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(32,10);cprintf("                        GESTION DES ETUDIANTS                          ");
    gotoxy(60,12);cprintf(" F1- Ajouter Etudient");
    gotoxy(60,14);cprintf(" F2- Consulter Etudient");
    gotoxy(60,16);cprintf(" F3- Modifier Etudient");
    gotoxy(60,18);cprintf(" F4- Supprimer Etudient");
    gotoxy(60,20);cprintf(" ESC- MENU");
    gotoxy(40,22);cprintf(" saisi votre choix : ");
    choix_Etudient();


}
 void gestionaire_Etudient()
{
    int j;
    system("COLOR f0");
    textbackground(LIGHTGRAY);textcolor(CYAN);
gotoxy(23,6);cprintf("                                   Gestion d'etudient                                     ");
textbackground(LIGHTGRAY);textcolor(BLACK);

    gotoxy(40,10);printf(" numero             :  .................................");
    gotoxy(40,12);printf(" Nom et Prenom      :  .................................");
    gotoxy(40,14);printf(" Code Apogee        :  .................................");
    gotoxy(40,16);printf(" filliere           :  .................................");
    gotoxy(40,18);printf(" Tel                :  .................................");
    gotoxy(40,20);printf(" Annee inscrit      :  .................................");
textbackground(LIGHTGRAY);textcolor(BLUE);
    gotoxy(23,27);cprintf(" F1: Ajouter      F2: Consulter         F3: Modifier        F4: Supprimer       ESC: MENU ");
                         for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                      gotoxy(22,5);printf("\332");

                      for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                      gotoxy(22,28);printf("\300");

                      for(j=0;j<=89;j++)
                            {
                              gotoxy(23+j,28);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                        gotoxy(113,5);printf("\277");
                                                        for(j=0;j<=74;j++)
                            {
                                gotoxy(30+j,8);printf("\304");
                            }
                      gotoxy(29,8);printf("\332");

                      for(j=0;j<=14;j++)
                            {
                              gotoxy(29,9+j);printf("\263");
                            }
                      gotoxy(29,24);printf("\300");

                      for(j=0;j<=74;j++)
                            {
                              gotoxy(30+j,24);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=14;j++)
                            {
                              gotoxy(105,23-j);printf("\263");
                            }
                        gotoxy(105,8);printf("\277");
}
int choix_Etudient()
 {
        char choix1;
 do{
                 gotoxy(70,22);
                 choix1=getch();
                if(choix1==59)
                  {
                 system("cls");
                 }
               switch(choix1)
                   {

                       case 59:  Ajouter_Etudient();
                              break;
                       case 60:consulter_Etudient();
                               break;
                       case 61:modification_Etudient();
                               break;
                       case 62:  supprimer_Etudient();
                               break;
                       case 27: menu_principale();
                               break;
                      default:gotoxy(23,29);textcolor(RED);textbackground(LIGHTGRAY);cprintf("VOTRE CHOIX EST INCORRECT ") ;

                               break;
                   }

}while(5);
return 0;
}
int nbree=0;
void Ajouter_Etudient()
{
    int exist1;
    system("cls");
gestionaire_Etudient();
    textbackground(GREEN);textcolor(WHITE);
    gotoxy(50,23);cprintf("  ENREGISTRER  ");
    gotoxy(70,23);cprintf("     ANNULER    ");
    if(nbree>100)
    {
      gotoxy(56,21);textcolor(1);textbackground(LIGHTGRAY); cprintf("table pleine!!!");
    } else
{    textcolor(BLUE);textbackground(LIGHTGRAY);

       list[nbree].numero = 1+nbree;
     gotoxy(75,10);printf("%d",list[nbree].numero);
       gotoxy(65,12);scanf("%s", list[nbree].Nom);
        gotoxy(75,14);scanf("%d",&list[nbree].code);
                exist1=chercher_code(list[nbree].code);
        if(exist1==-1){
        gotoxy(75,16);scanf("%s",list[nbree].filliere);
        gotoxy(70,18);scanf("%d",&list[nbree].Tel);
        gotoxy(75,20);scanf("%d",&list[nbree].Annee_inscrit);
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  le nouveau Etudiant est ajouter  ");
        nbree ++ ;}
            else{     textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  Etudiant deja inscrit sous num %d ",list[exist1].numero);}
    }
}
int chercher_Etudient(int id)
{
    int exit= -1,i;
    for( i=0 ;i<nbree ; i++)
    {
        if (id==list[i].numero )
        exit=i;
        }
     return exit;
}
int chercher_code(int id)
{
    int exit= -1,i;
    for( i=0 ;i<nbree ; i++)
    {
        if (id==list[i].code )
        exit=i;
        }
     return exit;
}
void modification_Etudient()
{
int idr,exit;
system("cls");
gestionaire_Etudient();
gotoxy(75,10);scanf("%d",&idr);
exit=chercher_Etudient(idr) ;
if(exit==-1)
{
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  Etudiant n'exist pas  ");
}
else{

    gotoxy(65,12); scanf("%s",list[exit].Nom);
    gotoxy(75,14); scanf("%d",&list[exit].code);
    gotoxy(75,16);scanf("%s",list[exit].filliere);
    gotoxy(75,18);scanf("%d",&list[exit].Tel);
    gotoxy(75,20);scanf("%d",&list[exit].Annee_inscrit);

 }
}
void consulter_Etudient()
{
    int i,exit,idr;
 system("cls");
 gestionaire_Etudient();
 textcolor(GREEN);textbackground(WHITE);

textbackground(GREEN);textcolor(WHITE);
    gotoxy(40,23);cprintf("    > >   ");
    gotoxy(55,23);cprintf("     >    ");
    gotoxy(70,23);cprintf("     <    ");
    gotoxy(85,23);cprintf("    < <   ");

gotoxy(75,10);scanf("%d",&idr);
exit=chercher_Etudient(idr);
if(exit==-1){
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  Etudiant n'exist pas  ");
}
else
{
    gotoxy(75,12);printf(" %s",list[exit].Nom);
    gotoxy(75,14); printf(" %d" ,list[exit].code);
    gotoxy(75,16);printf(" %s" ,list[exit].filliere);
    gotoxy(75,18);printf(" %d" ,list[exit].Tel);
    gotoxy(75,20);printf(" %d" ,list[exit].Annee_inscrit);


}
}
void supprimer_Etudient()
{
    int x,exit,i;
        system("cls");
    consulter_Etudient();
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(40,22);cprintf("        voulez vous supprimer : 1-oui  2-non           ");
    gotoxy(90,22);cscanf("%d",&x);
    if(x==2){gotoxy(40,22);cprintf("                suppression annuler          !!!   "); }
/*gestionaire_Etudient();
 gotoxy(75,10);scanf("%d",&idr);
exit=chercher_Etudient(idr);
if(exit==-1)
{
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  Etudiant n'exist pas  ");*/

else{
        for (i=exit;i<nbree-1;i++)
        {
            list[i].numero=list[i+1].numero;
            strcpy(list[i].Nom,list[i+1].Nom);
            list[i].code=list[i+1].code;
            strcpy(list[i].filliere,list[i+1].filliere);
            list[i].Tel=list[i+1].Tel;
            list[i].Annee_inscrit=list[i+1].Annee_inscrit;
        }
            textbackground(LIGHTGRAY);textcolor(CYAN);
            gotoxy(45,22);cprintf("           Etudiant est supprimer                 ");
        nbree--;
}
}

void menu_ouvrage()
{

    cadre();
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(32,10);cprintf("                        GESTION DES OUVRAGES                           ");
    gotoxy(60,12);cprintf(" F1- Ajouter Ouvrage");
    gotoxy(60,14);cprintf(" F2- Consulter Ouvrage");
    gotoxy(60,16);cprintf(" F3- Modifier Ouvrage");
    gotoxy(60,18);cprintf(" F4- Supprimer Ouvrage");
    gotoxy(60,20);cprintf(" ESC- MENU");
    gotoxy(40,22);cprintf(" saisi votre choix : ");
    choix_ouvrage();
    system("cls");

}
void gestionaire_ouvrage()
{
    int j;
    system(" color f0");
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(23,6);cprintf("                                 GESTION DES OUVRAGES                                     ");
    textbackground(LIGHTGRAY);textcolor(BLACK);
    gotoxy(23,5);cprintf("                                                                                          ");
    gotoxy(40,10);printf("Numero          :  ....................................");
    gotoxy(40,12);printf("Titre           :  ....................................");
    gotoxy(40,14);printf("Annee d'edition :  ....................................");
    gotoxy(40,16);printf("Auteur          :  ....................................");
    gotoxy(40,18);printf("Specialte       :  ....................................");
    textbackground(LIGHTGRAY);textcolor(BLUE);
    gotoxy(23,27);cprintf("F1: Nouveau        F2: Consulter         F3: Modifier        F4: Supprimer       ESC: MENU");
                         for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                      gotoxy(22,5);printf("\332");

                      for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                      gotoxy(22,28);printf("\300");

                      for(j=0;j<=89;j++)
                            {
                              gotoxy(23+j,28);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                        gotoxy(113,5);printf("\277");
                                                        for(j=0;j<=74;j++)
                            {
                                gotoxy(30+j,8);printf("\304");
                            }
                      gotoxy(29,8);printf("\332");

                      for(j=0;j<=14;j++)
                            {
                              gotoxy(29,9+j);printf("\263");
                            }
                      gotoxy(29,24);printf("\300");

                      for(j=0;j<=74;j++)
                            {
                              gotoxy(30+j,24);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=14;j++)
                            {
                              gotoxy(105,23-j);printf("\263");
                            }
                        gotoxy(105,8);printf("\277");
}
int choix_ouvrage()
{
        char choix1;
 do{
                 gotoxy(70,22);
                 choix1=getch();
                if(choix1==59)
                  {
                 system("cls");
                 }
               switch(choix1)
                   {

                       case 59:  system("cls");nouveau_ouvrage();
                              break;
                       case 60:  system("cls");consulter_ouvrage();
                               break;
                       case 61:  system("cls");modifier_ouvrage();
                               break;
                       case 62:  system("cls");supprimer_ouvrage();
                               break;
                       case 27: menu_principale();
                               break;
                      default:gotoxy(23,29);textcolor(RED);textbackground(LIGHTGRAY);cprintf("VOTRE CHOIX EST INCORRECT ") ;

                               break;
                   }

}while(5);
return 0;
}
int nbreo=0;
void nouveau_ouvrage()
{
    system("cls");
     gestionaire_ouvrage();
    textbackground(GREEN);textcolor(WHITE);
    gotoxy(50,22);cprintf("  ENREGISTRER  ");
    gotoxy(70,22);cprintf("     ANNULER    ");
  if(nbreo<100){
    livre[nbreo].numero=2000+nbreo;
    gotoxy(75,10);printf("%d",livre[nbreo].numero);
    gotoxy(75,12);scanf("%s",livre[nbreo].titre);
    gotoxy(75,14);scanf("%d",&livre[nbreo].annee);
    gotoxy(75,16);scanf("%s",livre[nbreo].auteur);
    gotoxy(75,18);scanf("%s",livre[nbreo].specialite);
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(55,20);cprintf("  le nouveau livre est ajouter  ");
    nbreo++;}
    else{ printf("le tableau est pleine");}

}
int chercher_ouvrage(int id)
{
 int exist=-1,i;
    for(i=0;i<nbreo;i++){
        if(id==livre[i].numero)
            exist=i;
    }
    return exist;

}
void modifier_ouvrage()
{
    int idr,exist;
    system("cls");
    gestionaire_ouvrage();
    gotoxy(75,10);scanf("%d",&idr);
    exist=chercher_ouvrage(idr);
    if(exist==-1){
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,20);cprintf("  livre n'exist pas  ");
    }
    else{
    gotoxy(75,12);scanf("%s",livre[exist].titre);
    gotoxy(75,14);scanf("%d",&livre[exist].annee);
    gotoxy(75,16);scanf("%s",livre[exist].auteur);
    gotoxy(75,18);scanf("%s",livre[exist].specialite);}

}
void consulter_ouvrage()
{
        int idr,exist;
    system("cls");
    gestionaire_ouvrage();
    textbackground(GREEN);textcolor(WHITE);
    gotoxy(40,22);cprintf("    > >   ");
    gotoxy(55,22);cprintf("     >    ");
    gotoxy(70,22);cprintf("     <    ");
    gotoxy(85,22);cprintf("    < <   ");

    gotoxy(75,10);scanf("%d",&idr);
    exist=chercher_ouvrage(idr);
    if(exist==-1){
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,20);cprintf("  livre n'exist pas  ");
    }
    else{
    gotoxy(75,12);printf("%s",livre[exist].titre);
    gotoxy(75,14);printf("%d",livre[exist].annee);
    gotoxy(75,16);printf("%s",livre[exist].auteur);
    gotoxy(75,18);printf("%s",livre[exist].specialite);}
}
void supprimer_ouvrage()
{
    int x,exist,i;
    system("cls");
    consulter_ouvrage();
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(40,22);cprintf("        voulez vous supprimer : 1-oui  2-non           ");
    gotoxy(90,22);cscanf("%d",&x);
    if(x==2){gotoxy(40,22);cprintf("                suppression annuler          !!!   "); }
    /*gestionaire_ouvrage();
    gotoxy(75,10);scanf("%d",&idr);
    exist=chercher_ouvrage(idr);
    if(exist==-1){
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,20);cprintf("  livre n'exist pas  ");
    }*/
    else{
        for(i=exist;i<nbree-1;i++){
            livre[i].numero=livre[i+1].numero;
            strcpy(livre[i].titre,livre[i+1].titre);
            livre[i].annee=livre[i+1].annee;
            strcpy(livre[i].auteur,livre[i+1].auteur);
            strcpy(livre[i].specialite,livre[i+1].specialite);
        }
            textbackground(LIGHTGRAY);textcolor(CYAN);
            gotoxy(45,22);cprintf("              Ouvrage est supprimer                ");
        nbree--;
    }

}

void menu_pret()
{
    system("cls");
    cadre();
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(32,10);cprintf("                        GESTION DES PRETS                             ");
    gotoxy(60,12);cprintf(" F1- Ajouter PRETS");
    gotoxy(60,14);cprintf(" F2- Consulter PRETS");
    gotoxy(60,16);cprintf(" F3- Modifier PRETS");
    gotoxy(60,18);cprintf(" F4- Supprimer PRETS");
    gotoxy(60,20);cprintf(" ESC- MENU");
    gotoxy(40,22);cprintf(" saisi votre choix : ");
    choix_pret();
    system("cls");

}
void gestionaire_pret()
{
     int j;
    system(" color f0");

    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(23,6);cprintf("                                 GESTION DES PRETS                                        ");
    textbackground(LIGHTGRAY);textcolor(BLACK);
    gotoxy(23,5);cprintf("                                                                                          ");
    gotoxy(40,10);printf("Numero de pret          :  .................................");
    gotoxy(40,12);printf("Numero d'etudient       :  .................................");
    gotoxy(40,14);printf("Numero d'ouvrage        :  .................................");
    gotoxy(40,16);printf("Date de debut de pret   :  _//_");
    gotoxy(40,18);printf("Debut de retour         :  _//_");
    gotoxy(70,20);printf("Duree du pret  :  ..........");
    textbackground(LIGHTGRAY);textcolor(BLUE);
    gotoxy(23,27);cprintf("F1: Nouveau        F2: Consulter         F3: Modifier        F4: Supprimer       ESC: MENU");
                         for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                      gotoxy(22,5);printf("\332");

                      for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                      gotoxy(22,28);printf("\300");

                      for(j=0;j<=89;j++)
                            {
                              gotoxy(23+j,28);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                        gotoxy(113,5);printf("\277");
                                                        for(j=0;j<=74;j++)
                            {
                                gotoxy(30+j,8);printf("\304");
                            }
                      gotoxy(29,8);printf("\332");

                      for(j=0;j<=14;j++)
                            {
                              gotoxy(29,9+j);printf("\263");
                            }
                      gotoxy(29,24);printf("\300");

                      for(j=0;j<=74;j++)
                            {
                              gotoxy(30+j,24);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=14;j++)
                            {
                              gotoxy(105,23-j);printf("\263");
                            }
                        gotoxy(105,8);printf("\277");

}
int choix_pret()
{
        char choix1;
 do{
                 gotoxy(70,22);
                 choix1=getch();
                if(choix1==59)
                  {
                 system("cls");
                 }
               switch(choix1)
                   {

                       case 59:  system("cls");nouveau_pret();
                              break;
                       case 60:  system("cls");consulter_pret();
                               break;
                       case 61:  system("cls");modifier_pret();
                               break;
                       case 62:  system("cls");supprimer_pret();
                               break;
                       case 27: menu_principale();
                               break;
                      default:gotoxy(23,29);textcolor(RED);textbackground(LIGHTGRAY);cprintf("VOTRE CHOIX EST INCORRECT ") ;

                               break;
                   }

}while(5);
return 0;
}
int nbrep=0;
void nouveau_pret()
{
    int exist1;
    system("cls");
     gestionaire_pret();
    textbackground(GREEN);textcolor(WHITE);
    gotoxy(50,22);cprintf("  ENREGISTRER  ");
    gotoxy(70,22);cprintf("     ANNULER    ");
  if(nbree<100){
    pret[nbrep].numero=1+nbrep;
    gotoxy(75,10);printf("%d",pret[nbrep].numero);
    gotoxy(75,12);scanf("%d",&pret[nbrep].ne);
        exist1=chercher_ne(pret[nbrep].ne);
        if(exist1==-1){
    gotoxy(75,14);scanf("%d",&pret[nbrep].no);
    gotoxy(67,16);scanf("%d",&pret[nbrep].jour1);
    gotoxy(70,16);scanf("%d",&pret[nbrep].mois1);
    gotoxy(73,16);scanf("%d",&pret[nbrep].ann1);
    gotoxy(67,18);scanf("%d",&pret[nbrep].jour2);
    gotoxy(70,18);scanf("%d",&pret[nbrep].mois2);
    gotoxy(73,18);scanf("%d",&pret[nbrep].ann2);
    pret[nbrep].duree=duree(pret[nbrep].jour1,pret[nbrep].mois1,pret[nbrep].jour2,pret[nbrep].mois2);
    gotoxy(89,20);printf("%d jours",pret[nbrep].duree);
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(55,21);cprintf("  le nouveau pret est ajouter  ");
    nbrep++;}
    else{     textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  Etudiant deja fait un pret sous num  %d  ",pret[exist1].numero);}
}
    else{ printf("le tableau est pleine");}
}
int duree(int j1,int m1,int j2,int m2)
{
    int d,jj_aide,j=0,i;
if(m1<=m2){
    for(i=m1;i<m2;i++){
    switch(i)
    {
        case 1:  jj_aide = 31; break;
        case 2:  jj_aide = 28; break;
        case 3:  jj_aide = 31; break;
        case 4:  jj_aide = 30; break;
        case 5:  jj_aide = 31; break;
        case 6:  jj_aide = 30; break;
        case 7:  jj_aide = 31; break;
        case 8:  jj_aide = 31; break;
        case 9:  jj_aide = 30; break;
        case 10: jj_aide = 31; break;
        case 11: jj_aide = 30; break;
        case 12: jj_aide = 31; break;
    }
    j=j+jj_aide;}
    d=j-j1+j2;}
    else{
        d=duree(j1,m1,31,12)+duree(0,1,j2,m2);
    }
    return d;

}
int chercher_pret(int id)
{
 int exist=-1,i;
    for(i=0;i<nbrep;i++){
        if(id==pret[i].numero)
            exist=i;
    }
    return exist;

}
int chercher_ne(int id)
{
 int exist=-1,i;
    for(i=0;i<nbrep;i++){
        if(id==pret[i].ne)
            exist=i;
    }
    return exist;

}
int chercher_no(int id)
{
 int exist=-1,i;
    for(i=0;i<nbrep;i++){
        if(id==pret[i].no)
            exist=i;
    }
    return exist;

}
void modifier_pret()
{
    int idr,exist;
    gestionaire_pret();
    gotoxy(75,10);scanf("%d",&idr);
    exist=chercher_pret(idr);
    if(exist==-1){
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  pret n'exist pas  ");
    }
    else{
    gotoxy(75,12);scanf("%d",&pret[exist].ne);
    gotoxy(75,14);scanf("%d",&pret[exist].no);
    gotoxy(67,16);scanf("%d",&pret[exist].jour1);
    gotoxy(70,16);scanf("%d",&pret[exist].mois1);
    gotoxy(73,16);scanf("%d",&pret[exist].ann1);
    gotoxy(67,18);scanf("%d",&pret[exist].jour2);
    gotoxy(70,18);scanf("%d",&pret[exist].mois2);
    gotoxy(73,18);scanf("%d",&pret[exist].ann2);
    pret[exist].duree=duree(pret[exist].jour1,pret[exist].mois1,pret[exist].jour2,pret[exist].mois2);
    gotoxy(89,20);printf("%d jours",pret[exist].duree);}
               textbackground(LIGHTGRAY);textcolor(CYAN);
            gotoxy(55,21);cprintf("  pret est modifier  ");
}
void consulter_pret()
{
    int idr,exist;
    system("cls");
    gestionaire_pret();
    textbackground(GREEN);textcolor(WHITE);
    gotoxy(40,22);cprintf("    > >   ");
    gotoxy(55,22);cprintf("     >    ");
    gotoxy(70,22);cprintf("     <    ");
    gotoxy(85,22);cprintf("    < <   ");

    gotoxy(75,10);scanf("%d",&idr);
    exist=chercher_pret(idr);
    if(exist==-1){
                textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  pret n'exist pas  ");
    }
    else{
    gotoxy(75,12);printf("%d",pret[exist].ne);
    gotoxy(75,14);printf("%d",pret[exist].no);
    gotoxy(67,16);printf("%d",pret[exist].jour1);
    gotoxy(70,16);printf("%d",pret[exist].mois1);
    gotoxy(73,16);printf("%d",pret[exist].ann1);
    gotoxy(67,18);printf("%d",pret[exist].jour2);
    gotoxy(70,18);printf("%d",pret[exist].mois2);
    gotoxy(73,18);printf("%d",pret[exist].ann2);
    gotoxy(94,20);printf("%d",pret[exist].duree);}
}
void supprimer_pret()
{
    int x,exist,i;
        system("cls");
    consulter_pret();
    textbackground(LIGHTGRAY);textcolor(CYAN);
    gotoxy(40,22);cprintf("        voulez vous supprimer : 1-oui  2-non           ");
    gotoxy(90,22);cscanf("%d",&x);
    if(x==2){gotoxy(40,22);cprintf("                suppression annuler          !!!   "); }
    /*gestionaire_pret();
    gotoxy(75,12);scanf("%d",&idr);
    exist=chercher_pret(idr);
    if(exist==-1){
        textbackground(LIGHTGRAY);textcolor(CYAN);
        gotoxy(55,21);cprintf("  pret n'exist pas  ");
    }*/
    else{
        for(i=exist;i<nbree-1;i++){
            pret[i].numero=pret[i+1].numero;
            pret[i].ne=pret[i+1].ne;
            pret[i].no=pret[i+1].no;
            pret[i].jour1=pret[i+1].jour1;
            pret[i].mois1=pret[i+1].mois1;
            pret[i].ann1=pret[i+1].ann1;
            pret[i].jour2=pret[i+1].jour2;
            pret[i].mois2=pret[i+1].mois2;
            pret[i].ann2=pret[i+1].ann2;
            pret[i].duree=pret[i+1].duree;

        }
           textbackground(LIGHTGRAY);textcolor(CYAN);
            gotoxy(45,22);cprintf("           pret est supprimer         ");
        nbrep--;
    }

}
void generation_pret()
{
    int choix;
    textbackground(BLUE);textcolor(LIGHTGREEN);
    gotoxy(40,9);cprintf("                                            ");
    gotoxy(40,10);cprintf("             GENERATION D'ETATS             ");
    gotoxy(40,11);cprintf("                                            ");
    gotoxy(40,13);cprintf("                                            ");
    gotoxy(40,14);cprintf("         1- PRETS EN COURS                  ");
    gotoxy(40,15);cprintf("                                            ");
    gotoxy(40,16);cprintf("         2- QUITTER                         ");
    gotoxy(40,17);cprintf("                                            ");
    do{
    gotoxy(40,19);cprintf("  Entree votre choix :                      ");
    gotoxy(70,19);cscanf("%d",&choix);}
    while(choix!=1&&choix!=2);
    switch(choix){
        case 1: system("cls");pret_encour();break;
        case 2: system("cls");menu_principale();break;
    }}


void pret_encour()
{
            int i,k,j,exist1,exist2;
            system("cls");

             for(j=0;j<=117;j++)
                            {
                                gotoxy(2+j,4);printf("\304");
                            }
                             for(j=0;j<=118;j++)
                               {
                                gotoxy(1+j,6);printf("\304");
                              }
                       gotoxy(1,4);
                       printf("\332");
                           for(j=0;j<=5+nbrep;j++)
                            {
                              gotoxy(1,5+j);printf("\263");
                              gotoxy(13,5+j);printf("\263");
                              gotoxy(34,5+j);printf("\263");
                              gotoxy(52,5+j);printf("\263");
                              gotoxy(70,5+j);printf("\263");
                              gotoxy(100,5+j);printf("\263");
                            }
                         gotoxy(1,5+j);
                       printf("\300");
                       k=j;
                     for(j=0;j<=117;j++)
                            {
                                gotoxy(2+j,5+k);printf("\304");
                            }

                        printf("\331");
                        for(j=0;j<=5+nbrep;j++)
                            {
                              gotoxy(120,10+nbrep-j);printf("\263");
                            }
                       gotoxy(120,10+nbrep-j);printf("\277");
              textcolor(0);textbackground(LIGHTGRAY);
            gotoxy(4,5);cprintf(" pret n ");
            gotoxy(16,5);cprintf(" Nom d'etudiant  ");
            gotoxy(36,5);cprintf(" Debut de pret ");
            gotoxy(54,5);cprintf(" Retour de pret ");
           gotoxy(82,5);cprintf("    Ouvrage    ");
            gotoxy(105,5);cprintf("  Specialite  ");


                      for(i=0;i<nbrep;i++)
              {
                gotoxy(4,8+i);printf("%3d",pret[i].numero);
                exist1=chercher_ne(pret[i].ne);
                gotoxy(16,8+i);printf("%s",list[exist1].Nom);
                gotoxy(36,8+i);printf("%d/%d/%d",pret[i].jour1,pret[i].mois1,pret[i].ann1);
                gotoxy(54,8+i);printf("%d/%d/%d",pret[i].jour2,pret[i].mois2,pret[i].ann2);
                exist2=chercher_no(pret[i].no);
                gotoxy(82,8+i);printf("%s",livre[exist2].titre);
                gotoxy(105,8+i);printf("%s",livre[exist2].specialite);
                }

            }

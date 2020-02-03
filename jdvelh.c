#include <stdio.h>
#include <string.h>
#include <windows.h>


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
struct Chapitre{

	char description[300];
  int gain_or;
	int gain_vie;
  int ID[2];
};

typedef struct Chapitre chapitre;

struct Lieux{

	char name[20];
	int distance;
};

typedef struct Lieux lieux;

void villes(){
  lieux Elvira ={"Elvira",3};
  lieux PayaKaroon ={"Paya-Karoon",5};

    //Elvira :
    printf("[1]     La tour d\'%s\n", Elvira.name);
    printf("        Distance : %d km\n\n", Elvira.distance);
    //PayaKaroon :
    printf("[2]     Village de %s\n", PayaKaroon.name);
    printf("        Distance : %d km\n\n", PayaKaroon.distance);
}




void main(){
  int ChoixJoueur = 0;
  int vie = 50;
  int or = 50;

  chapitre Chapitre1 ={"Vous arrivez au portes de la tour d\'Elvira\nVous avez marcher longtemps cela vous a fait perdre votre endurance ",50, - 5,{3,5}};
  chapitre Chapitre3 ={"Apres avoir rebrousser chemin vous vous perdez dans la foret\n",0,70,{0}};
  chapitre Chapitre5 ={"Vous entrer dans le donjon,\nVous recuperer un coffre rempli d\'Or ",500,0,};
  chapitre Chapitre2 ={"Apres avoir mis un pied dans la boue, un panneau indique : Village de PayaKaroon\n\nVous avez trouver sur la route un sac de pieces et des vielles bottes de chevalier\n\n      ( Vie +10 )\n      ( Or + 50 )\n",50,10,{2,4}};
  chapitre Chapitre4 ={"Vous sortez une arme mais tout les habitants sont des chasseurs de primes,\nIls vous tue.\n     ( Vie - 60)\n\n",0,60,{0}};
  chapitre Chapitre6 ={"Vous allez parler a un habitant qui vous donne une mystérieuse carte et une potion\n",10,50,{0}};

    printf("\n\nBienvenue a toi,");
    printf("                                       Inventaire :    Vie : %d    Or : %d    Arme : Arc",vie,or);
    printf("\n\nPour commencer Choisi entre ces 2 destination :\n\n");
    villes();
    printf("Destination choisie : ");
    scanf("%d", &ChoixJoueur);

      if (ChoixJoueur == 1){
              printf("\n%s", Chapitre1.description);
              printf("(Endurance %d)\n\n", Chapitre1.gain_vie);
              vie = vie + Chapitre1.gain_vie;
              printf("Vie : %d\n\n", vie);
              printf("2 choix s'offre a vous ici :\n\n");
              printf("Rebrousser chemin [3]       |       ");
              printf("Ouvrir les portes du Donjon [5]\n\n");
              printf("Choix : ");
              scanf("%d", &ChoixJoueur);

              if (ChoixJoueur == 3){
                printf("\n%s", Chapitre3.description);
                printf("Vous essayer de retrouver votre chemin mais en vain... (Vie -70)\n");
                vie = vie - Chapitre3.gain_vie;
                printf("Vie : %d\n\n", vie);
                printf("Votre seul Solution des d'utiliser un code de triche\n             |  Recommencer au debut [0]  |\n");
                printf("Choix : ");
                scanf("%d", &ChoixJoueur);
                while (vie >= 0){
                  if (ChoixJoueur == 0){
                    break;
                  }
                }
              }
              if (ChoixJoueur == 5){
                printf("\n%s", Chapitre5.description);
                printf("(Or + 500)\n");
                or = or + Chapitre5.gain_or;
                printf("Or : %d\n\n", or);
              }
      }

      if (ChoixJoueur == 2){
              printf("\n%s", Chapitre2.description);
              vie = vie + Chapitre2.gain_vie;
              or = or + Chapitre2.gain_or;
              printf("\nVie : %d\n\n", vie);
              printf("Or : %d\n\n", or);
              printf("2 choix s'offre a vous ici :\n\n");
              printf("Sortir son arme [4]       |       ");
              printf("Allez parler un ce vieux monsieur [6]\n\n");
              printf("Choix : ");
              scanf("%d", &ChoixJoueur);

              if (ChoixJoueur == 4){
                printf("\n%s", Chapitre4.description);
                vie = vie - Chapitre4.gain_vie;
                printf("Vie : %d\n\n", vie);
                printf("Votre seul Solution des d'utiliser un code de triche\n             |  Recommencer au debut [0]  |\n");
                printf("Choix : ");
                scanf("%d", &ChoixJoueur);
                while (vie >= 0){
                  if (ChoixJoueur == 0){
                    break;
                  }
                }
              }

      }

}

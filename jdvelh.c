#include <stdio.h>
#include <string.h>
#include <windows.h>


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

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
    printf("        Distance : %d km\n", PayaKaroon.distance);
}




void main(){
  int ChoixJoueur = 0;


    Color(12,0);
    printf("\nVilles les plus Proches :\n\n");
    Color(15,0);
    villes();
    Color(12,0);
    printf("\nChoisi ta destination :");
    scanf("%d", &ChoixJoueur);

      if (ChoixJoueur == 1){
              printf("\nVous arriver au portes de la tour D'Elvira\n");
      }
      if (ChoixJoueur == 2){
              printf("\nApres avoir mis un pied dans la boue, un panneau indique : Village de PayaKaroon\n");
      }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Objet
{
	char nom[20];
  int prix;
};

typedef struct Objet objet;

void triTableau(objet *tableau, int * index){
  objet trade;
  for (int i=0; i<*index-1;i++){
    if ((strcmp (tableau[i+1].nom, tableau[i].nom))<0){
      trade=tableau[i+1];
      tableau[i+1]=tableau[i];
      tableau[i]=trade;
    }
  }
}

void ajoutTableau(objet * thing, int * index, objet *tableau){
  printf("Prix: %d \n",(*thing).prix);
  tableau[*index]=*thing;

  *index=*index+1;
  triTableau(tableau,index);
}


void afficherTableau(objet *tableau, int index){
  for (int i=0; i<=index-1;i++){
    printf("Nom: %s  Prix: %d\n",tableau[i].nom,tableau[i].prix);
  }
}

int main(){
  int index=0;
  objet inventaire[20];
  objet tomate={"tomate",2};
  ajoutTableau(&tomate,&index,inventaire);
  objet yoyo={"yoyo",10};
  ajoutTableau(&yoyo,&index,inventaire);
  objet orange={"orange",20};
  ajoutTableau(&orange,&index,inventaire);
  afficherTableau(inventaire,index);
  printf("Index: %d \n",index);
  printf("Nom: %s  Prix: %d\n",inventaire[index].nom,inventaire[index].prix);
  printf("Nom: %d\n",strcmp(inventaire[index-1].nom,inventaire[index].nom));
	return 0;
}

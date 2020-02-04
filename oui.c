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
	int counter;
	while (counter!=*index){
		counter=1;
	  for (int i=0; i<*index-1;i++){
	    if (strcmp (tableau[i].nom, tableau[i+1].nom)>0){
	      trade=tableau[i];
	      tableau[i]=tableau[i+1];
	      tableau[i+1]=trade;
				printf("tri entre : %d et %d\n",i,i+1);
	    }
			else{
				counter++;
			}
	  }
	}
}

void ajoutTableau(objet * thing, int * index, objet *tableau){
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
	for(int i=0;i<3;i++){
		
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Objet
{
	char nom[20];
  int prix;
};

typedef struct Objet objet;

void triTableauInv(objet *tableau, int * index){
  objet trade;
	int counter;
	while (counter!=*index){
		counter=1;
	  for (int i=0; i<*index-1;i++){
	    if (strcmp (tableau[i].nom, tableau[i+1].nom)>0){
	      trade=tableau[i];
	      tableau[i]=tableau[i+1];
	      tableau[i+1]=trade;
	    }
			else{
				counter++;
			}
	  }
	}
}

void triTableauMar(objet *tableau, int * index){
  objet trade;
	int counter;
	while (counter!=*index){
		counter=1;
	  for (int i=0; i<*index-1;i++){
	    if (tableau[i].prix<tableau[i+1].prix){
	      trade=tableau[i];
	      tableau[i]=tableau[i+1];
	      tableau[i+1]=trade;
	    }
			else{
				counter++;
			}
	  }
	}
}

void ajoutTableauInv(objet * thing, int * index, objet *tableau){
  tableau[*index]=*thing;
  *index=*index+1;
	triTableauInv(tableau,index);
}

void ajoutTableauMar(objet * thing, int * index, objet *tableau){
  tableau[*index]=*thing;
  *index=*index+1;
	triTableauMar(tableau,index);
}

void enlever(int * choix, int * index, objet *tableau){
  for(int i=*choix;i<*index-1;i++){
		tableau[i]=tableau[i+1];
	}
	*index-=1;
}

void afficherTableauInv(objet *tableau, int index){
	printf("Voici le contenu de votre inventaire:\n");
  for (int i=0; i<=index-1;i++){
    printf("Nom: %s  Prix: %d\n",tableau[i].nom,tableau[i].prix);
  }
}

void afficherTableauMar(objet *tableau, int index){
	printf("Voici le contenu des produits du marchant:\n");
  for (int i=0; i<=index-1;i++){
    printf("%d: Nom: %s  Prix: %d\n",i+1,tableau[i].nom,tableau[i].prix);
  }
}

int main(){
  int indexI=0;
	int indexM=0;
	int choix;
  objet inventaire[20];
	objet marchant[20];
  objet tomate={"tomate",2};
  ajoutTableauInv(&tomate,&indexI,inventaire);
  objet yoyo={"yoyo",10};
  ajoutTableauInv(&yoyo,&indexI,inventaire);
  objet orange={"orange",20};
  ajoutTableauInv(&orange,&indexI,inventaire);
	objet epeeInfinite={"epee d'infinite",1};
	ajoutTableauMar(&epeeInfinite,&indexM,marchant);
	objet onglePied={"ongle de pied",10000};
	ajoutTableauMar(&onglePied,&indexM,marchant);
	objet photoPoivron={"photo de poivron",5000};
	ajoutTableauMar(&photoPoivron,&indexM,marchant);
	for(int i=0;i<3;i++){
		afficherTableauInv(inventaire, indexI);
		afficherTableauMar(marchant, indexM);
		printf("Choisissez l'item de votre choix:\n");
		scanf("%d",&choix);
		ajoutTableauInv(&marchant[choix-1],&indexI,inventaire);
		enlever(&choix,&indexM,marchant);
		printf("indexM %d\n",indexM);
	}
	return 0;
}

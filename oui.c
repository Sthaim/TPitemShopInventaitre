#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Objet
{
	char* nom;
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
	    if (tableau[i].prix>tableau[i+1].prix){
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
	if(*index<20){
	  tableau[*index]=*thing;
	  *index=*index+1;
		triTableauInv(tableau,index);}
	else{
		printf("Plus de place dans l'inventaire\n");
	}
}

void ajoutTableauMar(objet * thing, int * index, objet *tableau){
	if(*index<20){
	  tableau[*index]=*thing;
	  *index=*index+1;
		triTableauMar(tableau,index);}
	else{
		printf("Plus de place chez le marchand\n");
	}
}

void creationTableauMar(int * index, objet *tableau){
	if(*index<20){
		char newobjet_nom[32];
    int newobjet_prix;
    printf("Nouvel article\n Nom : ");
    scanf("%31s", &newobjet_nom);
		printf("Nom : %s\n",newobjet_nom);
    printf("Prix : ");
    scanf("%d", &newobjet_prix);
		objet newobjet = {newobjet_nom, newobjet_prix};
	  tableau[*index]=newobjet;
	  *index=*index+1;
		triTableauMar(tableau,index);}
	else{
		printf("Plus de place chez le marchand\n");
	}
}

void enlever(int * choix, int * index, objet *tableau){
  for(int i=*choix-1;i<*index-1;i++){
		tableau[i]=tableau[i+1];
	}
	*index-=1;
	triTableauMar(tableau,index);
}

void afficherTableauInv(objet *tableau, int index){
	printf("Voici le contenu de votre inventaire:\n");
  for (int i=0; i<=index-1;i++){
    printf("Nom: %s  Prix: %d\n",tableau[i].nom,tableau[i].prix);
  }
}

void afficherTableauMar(objet *tableau, int index){
	printf("Voici le contenu des produits du marchand:\n");
  for (int i=0; i<=index-1;i++){
    printf("%d: Nom:%s  Prix: %d\n",i+1,tableau[i].nom,tableau[i].prix);
  }
}

int main(){
  int indexI=0;
	int indexM=0;
	int choix;
  objet inventaire[20];
	objet marchand[20];
  objet tomate={"tomate",2};
  ajoutTableauInv(&tomate,&indexI,inventaire);
  objet yoyo={"yoyo",10};
  ajoutTableauInv(&yoyo,&indexI,inventaire);
  objet orange={"orange",20};
  ajoutTableauInv(&orange,&indexI,inventaire);
	objet epeeInfinite={"epee d'infinite",1};
	ajoutTableauMar(&epeeInfinite,&indexM,marchand);
	objet onglePied={"ongle de pied",10000};
	ajoutTableauMar(&onglePied,&indexM,marchand);
	objet photoPoivron={"photo de poivron",5000};
	ajoutTableauMar(&photoPoivron,&indexM,marchand);
	for(int i=0;i<3;i++){
		afficherTableauInv(inventaire, indexI);
		afficherTableauMar(marchand, indexM);
		printf("Choisissez l'item de votre choix:\n");
		scanf("%d",&choix);
		ajoutTableauInv(&marchand[choix-1],&indexI,inventaire);
		enlever(&choix,&indexM,marchand);
		creationTableauMar(&indexM,marchand);
	}
	return 0;
}

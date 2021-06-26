#include<stdio.h>
#include<stdlib.h>


typedef struct ELEMENT{
    int info;
    struct ELEMENT *SUIV;
}ELEMENT;

ELEMENT *empiler(ELEMENT *TETE,int x){
    ELEMENT *nouveau;
    nouveau=malloc(sizeof(ELEMENT));
    nouveau->info=x;
    //(*nouveau).info=x;
    nouveau->SUIV=TETE;
    TETE=nouveau;
    return TETE;
}

ELEMENT *depiler(ELEMENT *TETE){
    if(TETE!=NULL){
        ELEMENT *temp = TETE;
        TETE=TETE->SUIV;
        free(temp);
    }
    return TETE;
}

int elementEnTete(ELEMENT * TETE){
    if (TETE!=NULL)
        return TETE->info;
    return NULL;
}

void afficherPile(ELEMENT *TETE){
	if(TETE==NULL){
		printf("votre Pile est vide\n");
    }
	else{
		ELEMENT * parcours=TETE;
		printf("\n");
		while(parcours!=NULL){
			printf("<%d>\t",parcours->info);
			parcours=parcours->SUIV;
		}
		printf("\n");
	}
}

void main(){
    int choix, val;
    ELEMENT * TETE;
    printf("\n----- Implemenation des Piles -----\n");
    while(1){
        printf("\n***** MENU *****\n");
        printf("1. Creer Une Pile Vide\n");
        printf("2. Empiler\n");
        printf("3. Depiler\n");
        printf("4. Afficher la Pile\n");
        printf("5. Quitter\n");

        printf("\nEntrer votre choix: ");
        scanf("%d",&choix);

        switch(choix){
            case 1: TETE = NULL;
                    printf("\nUne Pile vide a ete cree");
                    break;
            case 2: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    TETE = empiler(TETE,val);
                    break;
            case 3: TETE = depiler(TETE);
                    break;
            case 4: afficherPile(TETE);
                    break;
            case 5: exit(0);
            default: printf("\nSVP Veuiller choisir parmi la liste des choix!!!\n");
      }
   }
   system ("pause");
}

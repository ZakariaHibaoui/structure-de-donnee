#include<stdio.h>
#include<stdlib.h>


typedef struct ELEMENT{
    int info;
    struct ELEMENT *SUIV;
} ELEMENT;

ELEMENT *enfiler(ELEMENT *TETE,int x){
    if (TETE==NULL){
        ELEMENT *nouveau, *parcours;
        nouveau = malloc(sizeof(ELEMENT));
        nouveau -> info = x;
        nouveau -> SUIV = NULL;
        TETE=nouveau;
    }
    else{
        ELEMENT *nouveau, *parcours;
        nouveau = malloc(sizeof(ELEMENT));
        nouveau -> info = x;
        nouveau -> SUIV = NULL;
        parcours = TETE;
        while (parcours->SUIV!=NULL){
            parcours=parcours->SUIV;
        }
        parcours->SUIV=nouveau;
    }
	return TETE;
}
/*
ELEMENT *defiler(ELEMENT *TETE){
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
*/
void afficherFile(ELEMENT *TETE){
	if(TETE == NULL){
		printf("votre File est vide\n");
    }
	else{
		ELEMENT * parcours = TETE;
		printf("\n");
		while(parcours != NULL){
			printf("<%d>\t",parcours->info);
			parcours = parcours->SUIV;
		}
		printf("\n");
	}
}

void main(){
    int choix, val;
    ELEMENT * TETE;
    printf("\n----- Implemenation des Files -----\n");
    while(1){
        printf("\n***** MENU *****\n");
        printf("1. Creer Une File Vide\n");
        printf("2. Enfiler\n");
        printf("3. Defiler\n");
        printf("4. Afficher la File\n");
        printf("5. Quitter\n");

        printf("\nEntrer votre choix: ");
        scanf("%d",&choix);

        switch(choix){
            case 1: TETE = NULL;
                    printf("\nUne File vide a ete cree");
                    break;
            case 2: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    TETE = enfiler(TETE,val);
                    break;
        /*    case 3: TETE = defiler(TETE);
                    break;*/
            case 4: afficherFile(TETE);
                    break;
            case 5: exit(0);
            default: printf("\nSVP Veuiller choisir parmi la liste des choix!!!\n");
      }
   }
   system ("pause");
}

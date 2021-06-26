#include<stdio.h>
#include<stdlib.h>

 typedef struct segment{
    double ax;
    double ay;
    double pox;
    double poy;
}segment;


typedef struct ELEMENT{
    segment s;
    struct ELEMENT *SUIV;
} ELEMENT;


ELEMENT *enfiler(ELEMENT *TETE,segment seg){
    if (TETE==NULL){

    	ELEMENT *nouveau;
        nouveau = malloc(sizeof(ELEMENT));
        nouveau -> s=seg;
        nouveau -> SUIV = NULL;
        TETE = nouveau;

    }
    else{
        ELEMENT *nouveau, *parcours;
        nouveau = malloc(sizeof(ELEMENT));
        nouveau -> s=seg;
        nouveau -> SUIV = NULL;
        parcours = TETE;
        while (parcours->SUIV!=NULL){
            parcours=parcours->SUIV;
        }
        parcours->SUIV=nouveau;
    }
	return TETE;
}

ELEMENT *defiler(ELEMENT *TETE){
    if(TETE!=NULL){
        ELEMENT *temp = TETE;
        TETE=TETE->SUIV;
        free(temp);
    }
    return TETE;
}


void afficherFile(ELEMENT *TETE){
	if(TETE == NULL){
		printf("votre File est vide\n");
    }
	else{
		ELEMENT * parcours = TETE;
		printf("\n");
		while(parcours != NULL){
			printf(" Segement : A(%x,%x),B(%x,%x) ",parcours->s.ax, parcours->s.ay,parcours->s.pox,parcours->s.poy);
			parcours = parcours->SUIV;
		}
		printf("\n");
	}
}


segment createsegment(){
    segment s;
    printf("\n ax: ");
    scanf("%x",&s.ax);
    printf("\n ay: ");
    scanf("%x", &s.ay);
    printf("\n pox: ");
    scanf("%x", &s.pox);
    printf("\n poy: ");
    scanf("%x", &s.poy);
    return s;
}


void main(){
    int choix;
    segment s;
    ELEMENT * TETE;
    printf("\n----- Implemenation des Files -----\n");
    while(1){
        printf("\n*** MENU ***\n");
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
            case 2: s=createsegment();
                    TETE = enfiler(TETE,s);
                    break;
            case 3: TETE = defiler(TETE);
                    break;
            case 4: afficherFile(TETE);
                    break;
            case 5: exit(0);
            default: printf("\nSVP Veuiller choisir parmi la liste des choix!!!\n");
      }
   }
   system ("pause");
}

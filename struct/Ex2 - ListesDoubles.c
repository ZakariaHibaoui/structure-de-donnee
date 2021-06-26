#include<stdio.h>
#include<stdlib.h>


typedef struct ELEMENT{
    int info;
    struct ELEMENT *PREC;
    struct ELEMENT *SUIV;
} ELEMENT;

ELEMENT *insererEnTete(ELEMENT *TETE,int x){
    ELEMENT *nouveau;
    nouveau = malloc(sizeof(ELEMENT));
    nouveau -> info = x;
    nouveau -> PREC = NULL;
    nouveau -> SUIV = TETE;
    if (TETE==NULL)
        TETE=nouveau;
    else{
        TETE -> PREC = nouveau;
        TETE = nouveau;
    }
    return TETE;
}

ELEMENT* insererEnQueue(ELEMENT* TETE, int x){
	if (TETE==NULL)
        return insererEnTete(TETE,x);

    ELEMENT *nouveau, *parcours;
    nouveau = malloc(sizeof(ELEMENT));
    nouveau -> info = x;
    parcours = TETE;
    while (parcours->SUIV != NULL){
        parcours = parcours->SUIV;
    }
    nouveau -> SUIV = NULL;
    nouveau -> PREC = parcours;
    parcours-> SUIV = nouveau;
    return TETE;
}

ELEMENT* insererAuMilieu(ELEMENT * TETE, int x, int y){
	if (TETE==NULL)
        return TETE;

    ELEMENT *parcours, *nouveau;
    parcours = TETE;
    while (parcours->info != x){
		parcours = parcours->SUIV;
		if(parcours==NULL){
            break;
        }
	}
    if (parcours==NULL)
        return TETE;

    if (parcours->SUIV==NULL)
        return insererEnQueue(TETE,y);

    nouveau = (ELEMENT*) malloc(sizeof (ELEMENT));
    nouveau -> info = y;
    nouveau -> PREC = parcours;
    nouveau -> SUIV = parcours->SUIV;
    parcours-> SUIV -> PREC = nouveau;
    parcours-> SUIV = nouveau;
    return TETE;
}

ELEMENT *supprimerEnTete(ELEMENT *TETE){
    if(TETE!=NULL){
        ELEMENT *temp;
        temp = TETE;
        TETE = TETE->SUIV;
        TETE->PREC = NULL;
        free(temp);
        return TETE;
    }
    return TETE;
}

ELEMENT *supprimerEnQueue(ELEMENT * TETE){
	if(TETE==NULL){
		return(TETE);
	}
	if (TETE->SUIV==NULL){
		free(TETE);
		TETE =NULL;
		return(TETE);
	}
	ELEMENT *temp;
    temp = TETE;
    while(temp->SUIV != NULL){
        temp = temp->SUIV;
    }
    temp->PREC->SUIV = NULL;
    free(temp);
    return TETE;
}

ELEMENT *supprimerAuMilieu(ELEMENT * TETE, int x){
    if(TETE==NULL){
		return TETE;
	}
	if (TETE->SUIV==NULL){
		if (TETE->info==x){
            free(TETE);
            TETE = NULL;
            return TETE;
		}
		else
            return TETE;
	}
    if(TETE->info==x)
        return supprimerEnTete(TETE);

	ELEMENT *temp;
    temp = TETE;
    while(temp->info != x){
        temp = temp->SUIV;
        if (temp==NULL)
            break;
    }
    if (temp==NULL)
        return TETE;
    if (temp->SUIV==NULL)
        return supprimerEnQueue(TETE);

    temp->SUIV->PREC = temp->PREC;
    temp->PREC->SUIV = temp->SUIV;
    free(temp);
    return TETE;
}

void afficherListe(ELEMENT *TETE){
	if(TETE==NULL){
		printf("votre liste est vide\n");
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
    int choix, val, val2;
    ELEMENT * TETE;
    printf("\n----- Listes Doublement Chainees -----\n");
    while(1){
        printf("\n***** MENU *****\n");
        printf("1. Creer la Liste\n");
        printf("2. Inserer en tete de la liste\n");
        printf("3. Inserer au milieu de la liste\n");
        printf("4. Inserer en queue de la liste\n");
        printf("5. Supprimer en tete de la liste\n");
        printf("6. Supprimer au milieu de la liste\n");
        printf("7. Supprimer en queue de la liste\n");
        printf("8. Afficher la liste\n");
        printf("9. Quitter\n");

        printf("\nEntrer votre choix: ");
        scanf("%d",&choix);

        switch(choix){
            case 1: TETE = NULL;
                    printf("\nUne liste vide a ete cree");
                    break;
            case 2: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    TETE = insererEnTete(TETE,val);
                    break;
            case 3: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    printf("\nEntrer la valeur precedente: ");
                    scanf("%d", &val2);
                    TETE = insererAuMilieu(TETE,val2,val);
                    break;
            case 4: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    TETE = insererEnQueue(TETE,val);
                    break;
            case 5: TETE = supprimerEnTete(TETE);
                    break;
            case 6: printf("\nEntrer la valeur a supprimer: ");
                    scanf("%d", &val);
                    TETE = supprimerAuMilieu(TETE,val);
                    break;
            case 7: TETE = supprimerEnQueue(TETE);
                    break;
            case 8: afficherListe(TETE);
                    break;
            case 9: exit(0);
            default: printf("\nSVP Veuiller choisir parmi la liste des choix!!!\n");
      }
   }
   system ("pause");
}

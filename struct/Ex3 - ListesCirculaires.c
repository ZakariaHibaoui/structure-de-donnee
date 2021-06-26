#include<stdio.h>
#include<stdlib.h>


typedef struct ELEMENT{
    int info;
    struct ELEMENT *SUIV;
}ELEMENT;

ELEMENT *insererEnTete(ELEMENT *TETE,int x){
    ELEMENT *nouveau;
    nouveau = (ELEMENT*)malloc(sizeof(ELEMENT));
    nouveau -> info = x;
    if(TETE == NULL){
       TETE = nouveau;
       nouveau->SUIV = TETE;
    }
    else{
       ELEMENT *parcours = TETE;
       while(parcours -> SUIV != TETE)
          parcours = parcours->SUIV;
       nouveau->SUIV = TETE;
       TETE = nouveau;
       parcours->SUIV = TETE;
    }
    return TETE;
}

ELEMENT* insererAuMilieu(ELEMENT * TETE, int x, int y){
	if (TETE==NULL)
        return TETE;

	ELEMENT *parcours, *nouveau;
	parcours = TETE;
	while (parcours->info != x){
		parcours = parcours->SUIV;
		if (parcours==TETE)
            break;
	}
	if(parcours==TETE && parcours->info != x){
        return TETE;
	}
	else{
        nouveau = (ELEMENT*) malloc(sizeof (ELEMENT));
        nouveau -> info = y;
        nouveau -> SUIV = parcours->SUIV;
        parcours->SUIV= nouveau;
        return TETE;
	}
}

ELEMENT* insererEnQueue(ELEMENT* TETE, int x){
    ELEMENT *nouveau;
    nouveau = (ELEMENT*)malloc(sizeof(ELEMENT));
    nouveau -> info = x;
    if(TETE == NULL)
    {
       TETE = nouveau;
       nouveau -> SUIV = TETE;
    }
    else
    {
       ELEMENT *parcours = TETE;
       while(parcours -> SUIV != TETE)
          parcours = parcours -> SUIV;
       parcours->SUIV = nouveau;
       nouveau->SUIV = TETE;
    }
    return TETE;
}

ELEMENT *supprimerEnTete(ELEMENT *TETE){
    if(TETE == NULL)
      return TETE;

    if(TETE->SUIV == TETE){
            free(TETE);
            TETE = NULL;
            return TETE;
    }

    ELEMENT *temp = TETE, *parcours = TETE;
    while(parcours -> SUIV != TETE)
          parcours = parcours -> SUIV;
    TETE = TETE -> SUIV;
    parcours -> SUIV = TETE;
    free(temp);
    return TETE;
}

ELEMENT *supprimerEnQueue(ELEMENT * TETE){
    if(TETE == NULL)
      return TETE;

    if(TETE->SUIV == TETE){
            free(TETE);
            TETE = NULL;
            return TETE;
    }

    ELEMENT *prec = TETE, *parcours = TETE;
    while(parcours -> SUIV != TETE){
        prec = parcours;
        parcours = parcours -> SUIV;
    }
    prec->SUIV = TETE;
    free(parcours);
    return TETE;
}

ELEMENT *supprimerAuMilieu(ELEMENT * TETE, int x){
	if(TETE==NULL){
		return TETE;
	}
	if (TETE->SUIV==TETE){
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

	ELEMENT *temp,*parcours;
	parcours = TETE;
	while(parcours->SUIV->info!=x){
		parcours = parcours->SUIV;
		if(parcours==TETE)
            break;
	}

	if (parcours==TETE && parcours->SUIV->info!=x)
        return TETE;

    temp = parcours->SUIV;
    parcours->SUIV = parcours->SUIV->SUIV;
    free(temp);
    return TETE;
}

void afficherListe(ELEMENT *TETE){
	if(TETE==NULL){
		printf("\nvotre liste est vide\n");
    }
	else{
		ELEMENT * parcours=TETE;
		printf("\n");
		do{
            printf("<%d>\t",parcours->info);
			parcours=parcours->SUIV;
		}while(parcours!=TETE);
		printf("\n");
	}
}

void main(){
    int choix, val, val2;
    ELEMENT * TETE;
    printf("\n----- Listes Simplement Chainees -----\n");
    while(1){
        printf("\n***** MENU *****\n");
        printf("1. Créer la Liste\n");
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PERSONNE{
    char * cin;
    char * nom;
    char * prenom;
    int age;
}PERSONNE;


typedef struct ELEMENT{
    PERSONNE p;
    struct ELEMENT *SUIV;
}ELEMENT;

ELEMENT *insererEnTete(ELEMENT *TETE , PERSONNE pers){
    ELEMENT *nouveau;
    nouveau=malloc(sizeof(ELEMENT));
    nouveau->p=pers;
    //(*nouveau).info=x;
    nouveau->SUIV=TETE;
    TETE=nouveau;
    return TETE;
}

ELEMENT* insererAuMilieu(ELEMENT * TETE, PERSONNE pers, char *cin){
	if (TETE==NULL)
        return TETE;

	ELEMENT *parcours, *nouveau;
	parcours = TETE;
	while (strcmp(parcours->p.cin,cin)!=0){
        parcours = parcours->SUIV;
        if(parcours==NULL){
            break;
        }
    }
	if(parcours==NULL){
        return TETE;
	}
	else{
        nouveau = malloc(sizeof (ELEMENT));
        nouveau -> p = pers;
        nouveau -> SUIV = parcours->SUIV;
        parcours->SUIV= nouveau;
        return TETE;
	}
}

ELEMENT* insererEnQueue(ELEMENT* TETE, PERSONNE pers){
	if (TETE==NULL)
        TETE=insererEnTete(TETE,pers);
    else{
        ELEMENT *nouveau, *parcours;
        nouveau = malloc(sizeof(ELEMENT));
        nouveau -> p = pers;
        nouveau -> SUIV = NULL;
        parcours = TETE;
        while (parcours->SUIV!=NULL){
            parcours=parcours->SUIV;
        }
        parcours->SUIV=nouveau;
    }
	return TETE;
}

ELEMENT *supprimerEnTete(ELEMENT *TETE){
    if(TETE!=NULL){
        ELEMENT *temp = TETE;
        TETE=TETE->SUIV;
        free(temp);
    }
    return TETE;
}

ELEMENT *supprimerEnQueue(ELEMENT * TETE){
	if(TETE==NULL){
		return TETE;
	}
	if (TETE->SUIV==NULL){
		free(TETE);
		TETE =NULL;
		return TETE;
	}
	ELEMENT *Temp,*parcours;
	parcours = TETE;
	while(parcours->SUIV->SUIV != NULL){
		parcours = parcours->SUIV;
	}
	Temp = parcours->SUIV;
	parcours->SUIV = NULL;
	free(Temp);
	return TETE;
}

ELEMENT *supprimerAuMilieu(ELEMENT * TETE, char * cin){
	if(TETE==NULL){
		return TETE;
	}
	if (TETE->SUIV==NULL){
		if (strcmp(TETE->p.cin,cin)==0){
            free(TETE);
            TETE = NULL;
            return TETE;
		}
		else
            return TETE;
	}
	if(strcmp(TETE->p.cin,cin)==0)
        return supprimerEnTete(TETE);

	ELEMENT *temp,*parcours;
	parcours= TETE;
	while (strcmp(parcours->SUIV->p.cin,cin)!=0){

		parcours = parcours->SUIV;
		if(parcours==NULL){
            break;
        }
	}
	if (parcours==NULL)
        return TETE;
    temp = parcours->SUIV;
    parcours->SUIV = parcours->SUIV->SUIV;
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
			printf("CIN : %s, Nom : %s, Prenom : %s, Age : %d\n",parcours->p.cin,parcours->p.nom,parcours->p.prenom,parcours->p.age);
			parcours=parcours->SUIV;
		}
	}
}

int chercher(ELEMENT * TETE, char * cin){
    ELEMENT * parcours=TETE;
    while(parcours!=NULL){
		if(strcmp(parcours->p.cin,cin)==0)
            return 1;
		parcours=parcours->SUIV;
	}
	return 0;
}

int chercherParNom(ELEMENT * TETE, char * nom){
    ELEMENT * parcours=TETE;
    while(parcours!=NULL){
		if(strcmp(parcours->p.nom,nom)==0)
            return 1;
		parcours=parcours->SUIV;
    }
    return 0;
}

void afficherPersonne(PERSONNE p){
    printf("CIN : %s, Nom : %s, Prenom : %s, Age : %d\n",p.cin,p.nom,p.prenom,p.age);
}

void personnesParAge(ELEMENT * TETE, int ageMin, int ageMax){
    ELEMENT * parcours=TETE;
    while(parcours!=NULL){
		if(parcours->p.age>ageMin && parcours->p.age>ageMax)
            afficherPersonne(parcours->p);
		parcours=parcours->SUIV;
    }
}

void personnesParNom(ELEMENT * TETE, char c){
    ELEMENT * parcours=TETE;
    while(parcours!=NULL){
		if(parcours->p.nom[0]=='c')
            afficherPersonne(parcours->p);
		parcours=parcours->SUIV;
    }
}

PERSONNE creerPersonne(){
    PERSONNE pers;
    pers.cin=malloc(sizeof(8*sizeof(char)));
    pers.nom=malloc(sizeof(20*sizeof(char)));
    pers.prenom=malloc(sizeof(20*sizeof(char)));
    printf("\nCIN: ");
    scanf("%s", pers.cin);
    printf("\nNOM: ");
    scanf("%s", pers.nom);
    printf("\nPRENOM: ");
    scanf("%s", pers.prenom);
    printf("\nAGE: ");
    scanf("%d", &pers.age);
    return pers;
}

void save(ELEMENT * TETE, char * fichier){
    FILE * f = fopen(fichier,"w");
    ELEMENT * parcours = TETE;
    while(parcours!=NULL){
        fprintf(f,"%s\t%s\t%s\t%d\n",parcours->p.cin,parcours->p.nom,parcours->p.prenom,parcours->p.age);
        parcours=parcours->SUIV;
    }
    fclose(f);
}

ELEMENT * load(ELEMENT * TETE, char * fichier){
    FILE * f;
    if((f= fopen(fichier,"r"))!= NULL){
        PERSONNE pers;
        pers.cin=malloc(8*sizeof(char));
        pers.nom=malloc(20*sizeof(char));
        pers.prenom=malloc(20*sizeof(char));
        TETE=NULL;
        while(fscanf(f,"%s%s%s%d", pers.cin,pers.nom,pers.prenom,&pers.age)!=EOF){
            TETE=insererEnQueue(TETE,pers);
        }
        fclose(f);
    }
    return TETE;
}

void main(){
    int choix;
    PERSONNE p;
    p.cin = malloc(8*sizeof(char));
    p.nom = malloc(20*sizeof(char));
    p.prenom = malloc(20*sizeof(char));
    char * cin ;
    cin= malloc(8*sizeof(char));
    ELEMENT * TETE;
    printf("\n----- Listes Simplement Chainees -----\n");
    while(1){
        printf("\n***** MENU *****\n");
        printf("1. Creer Une Liste Vide\n");
        printf("2. Inserer en tete de la liste\n");
        printf("3. Inserer au milieu de la liste\n");
        printf("4. Inserer en queue de la liste\n");
        printf("5. Supprimer en tete de la liste\n");
        printf("6. Supprimer au milieu de la liste\n");
        printf("7. Supprimer en queue de la liste\n");
        printf("8. Afficher la liste\n");
        printf("9. Chercher une personne par CIN\n");
        printf("10. Quitter\n");
        printf("11. Enregistrer la liste\n");
        printf("12. Charger la liste\n");

        printf("\nEntrer votre choix: ");
        scanf("%d",&choix);

        switch(choix){
            case 1: TETE = NULL;
                    printf("\nUne liste vide a ete cree");
                    break;
            case 2: p=creerPersonne();
                    TETE = insererEnTete(TETE,p);
                    break;
            case 3: p=creerPersonne();
                    TETE = insererAuMilieu(TETE,p,cin);
                    break;
            case 4: p=creerPersonne();
                    TETE = insererEnQueue(TETE,p);
                    break;
            case 5: TETE = supprimerEnTete(TETE);
                    break;
            case 6: printf("\nEntrer le CIN de la personne a supprimer: ");
                    scanf("%s", cin);
                    TETE = supprimerAuMilieu(TETE,cin);
                    break;
            case 7: TETE = supprimerEnQueue(TETE);
                    break;
            case 8: afficherListe(TETE);
                    break;
            case 9: printf("\nEntrer le CIN de la personne a chercher: ");
                    scanf("%s", cin);
                    if (chercher(TETE, cin)==1)
                        printf("La personne existe ;)");
                    else
                        printf("La personne n'existe pas !");
                    break;
            case 10: exit(0);
            case 11: save(TETE,"personnes.txt"); break;
            case 12: TETE = load(TETE,"personnes.txt"); break;
            default: printf("\nSVP Veuiller choisir parmi la liste des choix!!!\n");
      }
   }
   system ("pause");

}

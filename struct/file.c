#include<stdio.h>
#include<stdlib.h>


typedef struct _segment{
    double Ax;
    double Ay;
    double Bx;
    double By;
} segment;


typedef struct ELEMENT{
    segment info;
    struct ELEMENT *SUIV;
} ELEMENT;

ELEMENT *enfiler(ELEMENT *TETE,segment x){
    ELEMENT *nouveau, *parcours;
        nouveau = (ELEMENT *)malloc(sizeof(ELEMENT));
        nouveau -> info = x;
        nouveau -> SUIV = NULL;
    if (TETE==NULL){
        return nouveau;
    }else{
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

segment* elementEnTete(ELEMENT * TETE){
    if (TETE!=NULL)
        return &(TETE->info);
    return NULL;
}

void afficherFile(ELEMENT *TETE){
	if(TETE == NULL){
		printf("votre File est vide\n");
    }
	else{
		ELEMENT * parcours = TETE;
		printf("\n");
		while(parcours != NULL){
			printf("Segment: A(%lf,%lf), B(%lf, %lf)\n",parcours->info.Ax, parcours->info.Ay, parcours->info.Bx, parcours->info.By);
			parcours = parcours->SUIV;
		}
		printf("\n");
	}
}

int getHorizontalSegmentsCount(ELEMENT * Tete)  {
    int count = 0;

    if (Tete == NULL)
        return count;

    ELEMENT *parcours = Tete;

    while (parcours->SUIV != NULL){
        if (parcours->info.Ay == parcours->info.By)
            ++count;

        parcours = parcours->SUIV;
    }

    return count;
}

ELEMENT * readFromFile(char * fileName, ELEMENT * Tete) {
    
    FILE *file = fopen(fileName, "r");
    while(!feof(file)) {
        segment seg;
        printf("hey\n");
        fscanf(file, "%lf%lf%lf%lf", seg.Ax, seg.Ay, seg.Bx, seg.By);
        Tete = enfiler(Tete, seg);
    }
    fclose(file);
    return Tete;
}

int main() {
    ELEMENT *tete = NULL;
    segment a;
    a.Ax = 1;
    a.Ay = 2;
    a.Bx = 3;
    a.By = 4;
    tete = enfiler(tete, a);
    segment b;
    b.Ax = 5;
    b.Ay = 6;
    b.Bx = 7;
    b.By = 8;
    tete = enfiler(tete, b);
    afficherFile(tete);
    tete = readFromFile("segment.txt", tete);
    printf("\nasa\n");
    afficherFile(tete);
    return 0;
}

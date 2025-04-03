/*Programme de calcul de moyenne
Programmeur : ADAMAH Kouevi Joseph
Objectif: D�v�llopper ma conaissance en c (Sous programme)
D�but : 26 Janvier � 23h
Fin : 27 Janvier � 1h00*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int nbreNote;
float tabNote[100][100];
int nbreEtudiant;
int i,j;
float moyenne[100];

float priseNote()
{
    printf("\nQuel est le nombre des etudiants de la classe ?\n\n");
    scanf("%d",&nbreEtudiant);
    printf("\nChaque etudiant a combien de note (c'ect � dire le nombre des matiers) ?\n");
    scanf("%d",&nbreNote);
    for (i=1; i<=nbreEtudiant; i++)
    {
        printf("\nVeuillez entrer les notes de l'etudiant %d\n",i);
        for (j=1; j<=nbreNote; j++)
        {
            scanf("%f",&tabNote[i][j]);
        }
    }
    return tabNote[100][100];
}

float CalculMoyenne()
{
    float sommeNote[100];
    //  float moyenne[100];
    for (j=1; j<=nbreEtudiant; j++)
    {
        for (i=1; i<=nbreNote; i++)
        {
            sommeNote[j]+=tabNote[j][i];
        }
    }

    for(j=1; j<=nbreEtudiant; j++)
    {
        printf("\nLa somme des notes de l'�tudiant %d est %f : \n\n",j,sommeNote[j]);
    }

    for (i=1; i<=nbreEtudiant; i++)
    {
        moyenne[i] = (sommeNote[i]/nbreNote);
        printf("\nMoyenne de l'�tudiant %d est : %.2f\n\n",i,moyenne[i]);

    }

    return moyenne[100];
}

float Clasification()
{
    float moyenneComparaison[100];
    float classification[100];
// Tableau � manipuler pour la recherche du premier jusqu'au dernier
    float plusGrand,echangeur;
    int cpt;
    for(i=1; i<=nbreEtudiant; i++)
    {
// Ici j'ai affect� les valeur du tableau de des moyenne � moyenneComparaison pour �viter de manipuler le tab des moyenne
        moyenneComparaison[i]=moyenne[i];
    }

    for(cpt=1; cpt<=nbreEtudiant; cpt++)
    {

        plusGrand = moyenneComparaison[cpt];
        for(i=2; i<=nbreEtudiant; i++)
        {
            if(plusGrand < moyenneComparaison[i])
            {
                echangeur =plusGrand;
                plusGrand = moyenneComparaison[i];
                moyenneComparaison[i] = echangeur;

            }
        }
        classification[cpt] = plusGrand;
    }
    // Proclamation des r�sultats
    for(i=1; i<=nbreEtudiant; i++)
    {
        for(j=1;j<= nbreEtudiant;j++)
        {
            if(classification[i] == moyenne [j])
            {
                printf("\nLe %d est l'�tudiant %d avec la moyenne %.2f\n",i,j,classification[i]);
            }
        }

    }

    return classification[100];
}
int main()
{
    int decision;
    do
    {
        setlocale(LC_CTYPE,"");
        priseNote();
        system("cls");
        CalculMoyenne();
        Clasification();
        printf("\nVoullez vous continuer ?\n");
        printf("\nTaper 1  pour OUI ou n'importe quoi pour non\n");
        scanf("%d",&decision);
        system("cls");
    }
    while(decision == 1);


    return 0;
}

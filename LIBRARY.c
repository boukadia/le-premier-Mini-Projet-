#include <stdio.h>
#include <string.h>

typedef struct
{
    char titre[50];
    char auteur[20];
    float prix;
    int quantite;
} library;
library book[100];
int Nbr_livres_total = 0, i = 0,somme;

void AjouteLivre()                              //Ajouter du livre avec son carateristique
{
    printf("Tapez le titre du livre : ");
    scanf(" %[^\n]s", &book[Nbr_livres_total].titre);
    printf("Tapez l'auteur du livre : ");
    scanf(" %[^\n]s", &book[Nbr_livres_total].auteur);
    printf("Tapez le prix du livre : ");
    scanf("%f", &book[Nbr_livres_total].prix);
    printf("Tapez la quantite du livre : ");
    scanf("%d", &book[Nbr_livres_total].quantite);
    Nbr_livres_total++;
}

void stock()                                 //calcule de sommes des livres et leurs quantites
{
    int i, somme =0;
    for (i=0 ; i < Nbr_livres_total; i++){
            somme += book[i].quantite;

    }
    printf("total de livres est :%d\n", somme);
}

void Affiche_List_livres()                   //Affichage des livres et leurs caracteristique
{

    for (int i = 0; i < Nbr_livres_total; i++){
        printf("Le livre %d \n", i+1);
        printf("     Titre:       %s\n", book[i].titre);
        printf("     Auteur:      %s\n", book[i].auteur);
        printf("     Le prix:     %.2f\n", book[i].prix);
        printf("     La quantite: %d\n", book[i].quantite);
    }
    printf("\n");
}

void Mettre_a_jour()                       //changer la quantite  d'un livre
{
    int Nouvelle_Quantite, found = 0;
    char cherche[20];
    printf("Tapez le titre du livre: ");
    scanf(" %[^\n]s", &cherche);
    for (i = 0; i <=Nbr_livres_total; i++)
     {

         if (strcmp((book[i].titre), cherche) == 0)
         {
            printf("Tapez la nouvelle quantite: ");
            scanf("%d",&Nouvelle_Quantite);
            book[i].quantite = Nouvelle_Quantite;
            printf("la quantite a ete modifie la nouvelle quantite est : %d \n", book[i].quantite);
            found++;
            break;
         }
        if(found!=0)
        {
                printf("le book n'exixte pas !");
                break;
        }
    }
    printf("\n");
}

int Recherche()                         //Recherche d'un livre par on titre
{
    int i;
    char rech[50];
    printf("tapez le titre du livre: ");
    scanf(" %[^\n]s", &rech);
    int disponible = 0;
    for (i = 0; i < Nbr_livres_total; i++)
    {
        if (strcmp(book[i].titre, rech) == 0)
        {
            disponible = 1;
            break;
        }
        else
            disponible = 0;
    }
    if (disponible == 1)
    {
        printf("ce livre est diponible et il reste %d pieces \n",book[i].quantite);
         return i;
    }
    else
    {
        printf("ce livre n'est pas diponible \n");
        return -1;
    }
        printf("\n");
}

void Supprime(){
    int index = Recherche();
    if(index != -1)
    {
        for(i = index ; i <= Nbr_livres_total-1 ; i++)
        {
            book[i] = book[i+1];
        }
        Nbr_livres_total--;
        printf("le livre a ete supprime\n");
    }
    else
        printf("le livre n'est pas disponible\n");
}



int main()
{
    library book[100];
    int choix;

    do
    {
         printf("1. ajoute un livre\n");
         printf("2. affichage de tous les livres\n");
         printf("3. recherche par un titre\n");
         printf("4. mettre a jour la quantite d'un livres\n");
         printf("5. supprime un livre \n");
         printf("6. affiche le nombre totale des livres au stock\n");
         printf("7. sortie\n");
         printf("-----------------choisir votre choix : ------------------------ \n");
         scanf("%d", &choix);
        switch (choix){

        case 1:
        {
            printf(" ----------Ajoute un livre---------\n");
            AjouteLivre();
            printf(" -------------------------------------------------------------\n");
            printf(" -------------------------------------------------------------\n");
        }
        break;
        case 2:
        {
            printf("----------Affichage de tous les livres---------- \n");
            Affiche_List_livres();
            printf(" -------------------------------------------------------------\n");
            printf(" -------------------------------------------------------------\n");
        }
        break;
        case 3:
        {
            printf("----------Recherche par un titre----------\n");
            Recherche();
            printf(" -------------------------------------------------------------\n");
            printf(" -------------------------------------------------------------\n");
        }
        break;
        case 4:
        {
            printf("----------Mettre a jour la quantite d'un livres----------\n");
            Mettre_a_jour();
            printf(" -------------------------------------------------------------\n");
            printf(" -------------------------------------------------------------\n");

        }
        break;
        case 5:
        {
            printf("----------Supprime un livre---------- \n");
            Supprime();
            printf(" -------------------------------------------------------------\n");
            printf(" -------------------------------------------------------------\n");
        }
        break;
        case 6:
        {
            stock();
            printf(" -------------------------------------------------------------\n");
            printf(" -------------------------------------------------------------\n");
        }
        break;

        default:
            printf("nombre invalid\n");
            break;
        }
    } while (choix != 7);

    return 0;
}

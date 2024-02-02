//
//  main.c
//  Jeu pendu
//
//  Created by Jordy Vuong on 31/01/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define nombreEssais 10

// Fonction pour afficher le mot masqué
void afficherMotMasque(const char* mot, const char* lettresTrouvees);

// Fonction pour vérifier si une lettre est dans le mot
int lettreDansMot(char lettre, const char* mot, char* lettresTrouvees);

int main() {

    // Choisir un mot aléatoire
    char* mot = "ordinateur";
    int longueurMot = strlen(mot);

    char lettresTrouvees[26];  // J'initialise les lettres
    memset(lettresTrouvees, 0, sizeof(lettresTrouvees)); // Je le met à 0

    int tentatives = 10; //nombre de tentatives

    printf("Bienvenue au jeu du Pendu!\n");
    printf("Les règles sont simple, il suffit de deviner le mot mystère en proposant des lettres.\n");

    while (1) {
        // Afficher le mot masqué
        afficherMotMasque(mot, lettresTrouvees);

        // Demander à l'utilisateur de deviner une lettre
        char lettreDonnee; //Pour stocker la lettre
        printf("Devinez une lettre : ");
        scanf(" %c", &lettreDonnee);

        // On vérifie si la lettre est dans le mot
        if (lettreDansMot(lettreDonnee, mot, lettresTrouvees)) {
            printf("Bonne devinette !\n");
        } else {
            printf("Incorrect. Essaie encore. Il vous reste %d essais\n", tentatives);
            tentatives--;

            // Vérifier si le joueur a perdu
            if (tentatives == nombreEssais) {
                printf("Désolé, vous avez perdu. Le mot était : %s\n", mot);
                break;
            }
        }

        // Vérifier si le joueur a gagné
        int aGagne = 1;
        for (int i = 0; mot[i] != '\0'; i++) {
            if (lettresTrouvees[i] == 0) {
                aGagne = 0;
                break;
            }
        }

        if (aGagne) {
            printf("Félicitations, vous avez gagné ! Le mot était : %s\n", mot);
            break;
        }
    }

    return 0;
}


void afficherMotMasque(const char* mot, const char* lettresTrouvees) {
    for (int i = 0; mot[i] != '\0'; i++) {  // on initialise, puis on donne la condition si elle doit être arrêté ou non, pour on met à jour la variable
        if (lettresTrouvees[i] == 1) { // Booléen, 1 si vrai, 0 si faux.
            printf("%c ", mot[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int lettreDansMot(char lettre, const char* mot, char* lettresTrouvees) {
    int trouve = 0;
    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] == lettre) {
            lettresTrouvees[i] = 1;
            trouve = 1;
        }
        if (i == strlen(mot) -1 && trouve == 1) {
            return 1;
        }
    }
    return 0;  // On n'a pas trouvé la lettre.
}

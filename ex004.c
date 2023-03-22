#include <stdio.h>

// Fonction pour saisir un tableau de n valeurs
int *saisirtab(int n) {
    int *tab = malloc(n * sizeof(int)); // Allocation dynamique de mémoire pour le tableau
    for (int i = 0; i < n; i++) {
        printf("tab(%d)=", i+1);
        scanf("%d", &tab[i]);
    }
    return tab;
}

// Procédure pour afficher les éléments d'un tableau
void afficher(int *T, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", T[i]);
    }
    printf("\n");
}

// Fonction pour supprimer les doublons d'un tableau
int suppdoublons(int *V, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        int doublon = 0;
        for (int k = 0; k < i; k++) {
            if (V[i] == V[k]) {
                doublon = 1;
                break;
            }
        }
        if (!doublon) {
            V[j] = V[i];
            j++;
        }
    }
    return j;
}

int main(){
int *P, n, nv;
printf("donner la dimension n = ");
scanf("%d", &n);
P=saisirtab(n);
printf("Le tableau apres suppression des doublons est:" );
nv=suppdoublons(P, n);
afficher(P,nv);
}








/*
int main() {
    int n;
    printf("donner la dimension n:\n");
    scanf("%d", &n);
    int *tab = saisirtab(n);
    afficher(tab, n);
    int n_compress = suppdoublons(tab, n);
    printf("Le tableau apres suppression des doublons est:\n");
    afficher(tab, n_compress);
    free(tab); // Libération de la mémoire allouée pour le tableau
    return 0;
}*/

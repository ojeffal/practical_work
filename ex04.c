#include <stdio.h>
#include <stdlib.h>

int *saisirtab(int n) {
    int *tab = (int *)malloc(n * sizeof(int));
    if(tab == NULL) {
        printf("Erreur d'allocation de mémoire.");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        printf("Entrez l'élément %d : ", i+1);
        scanf("%d", &tab[i]);
    }
    return tab;
}

void afficher(int *T, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int suppdoublons(int *V, int n) {
    int new_size = n;
    for(int i = 0; i < new_size; i++) {
        for(int j = i+1; j < new_size; j++) {
            if(V[i] == V[j]) {
                for(int k = j; k < new_size-1; k++) {
                    V[k] = V[k+1];
                }
                new_size--;
                j--;
            }
        }
    }
    return new_size;
}

int main() {
    int n = 6;
    int *tab = saisirtab(n);

    printf("Le tableau est : ");
    afficher(tab, n);

    int new_size = suppdoublons(tab, n);

    printf("Le tableau après suppression des doublons est : ");
    afficher(tab, new_size);

    free(tab);
    return 0;
}

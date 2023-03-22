//Inter


#include <stdio.h>

// Fonction pour supprimer les doublons dans un tableau
void suppdoublons(int *V, int *n) {
    int i, j, k;
    for (i = 0; i < *n; ++i) {
        for (j = i + 1; j < *n;) {
            if (V[j] == V[i]) {
                // Supprimer l'élément j
                for (k = j; k < *n - 1; ++k) {
                    V[k] = V[k + 1];
                }
                --*n;
            } else {
                ++j;
            }
        }
    }
}

// Fonction pour calculer l'intersection de deux tableaux
void Inter(int *V1, int *V2, int n1, int n2, int *V, int *n) {
    int i, j;
    *n = 0;  // Initialiser le nombre d'éléments dans V à 0
    for (i = 0; i < n1; ++i) {
        for (j = 0; j < n2; ++j) {
            if (V1[i] == V2[j]) {
                V[(*n)++] = V1[i];
                break;  // Passer à l'élément suivant dans V1
            }
        }
    }
    suppdoublons(V, n);
}

int main() {
    int V1[6] = {2, 34, 5, 12, 14, 2};
    int V2[4] = {34, 12, 78, 21};
    int V[10];  // Tableau résultant
    int n;      // Nombre d'éléments dans le tableau résultant
    Inter(V1, V2, 6, 4, V, &n);
    printf("Le tableau Intersection est :\n");
    for (int i = 0; i < n; ++i) {
        printf("tab(%d) = %d\n", i, V[i]);
    }
    return 0;
}

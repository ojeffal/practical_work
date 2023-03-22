//Diff

void Diff(int *V1, int *V2, int n1, int n2, int *V, int *n) {
    // Initialisation de V et n
    *n = 0;
    // Parcours de V1
    for (int i = 0; i < n1; i++) {
        int found = 0;
        // Parcours de V2 pour chercher la valeur de V1[i]
        for (int j = 0; j < n2; j++) {
            if (V1[i] == V2[j]) {
                found = 1;
                break;
            }
        }
        // Si la valeur n'est pas dans V2, on l'ajoute à V
        if (!found) {
            V[*n] = V1[i];
            (*n)++;
        }
    }
    // Suppression des doublons dans V
    suppdoublons(V, n);
}


#include <stdio.h>

void Diff(int *V1, int *V2, int n1, int n2, int *V, int *n);
void suppdoublons(int *V, int *n);

int main() {
    int V1[6] = {12, 34, 34, 67};
    int V2[6] = {12, 234, 1, 90, 12, 12};
    int V[6];
    int n;
    Diff(V1, V2, 4, 6, V, &n);
    printf("Le tableau difference est : \n");
    for (int i = 0; i < n; i++) {
        printf("tab(%d) = %d\n", i, V[i]);
    }
    return 0;
}

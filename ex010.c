// Méthode des maximums successifs:



void tri_maximums(int tab[], int n) {
    int i, j, max, temp;
    for (i = 0; i < n-1; i++) {
        max = i;
        for (j = i+1; j < n; j++) {
            if (tab[j] > tab[max]) {
                max = j;
            }
        }
        temp = tab[i];
        tab[i] = tab[max];
        tab[max] = temp;
    }
}


// Méthode à bulles:

void tri_bulles(int tab[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (tab[j] < tab[j+1]) {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}



// Méthode par insertion:


void tri_insertion(int tab[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = tab[i];
        j = i-1;
        while (j >= 0 && tab[j] < temp) {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = temp;
    }
}




#include <stdio.h>

int main() {
    int n, i;
    printf("Entrez la taille du vecteur: ");
    scanf("%d", &n);
    int tab[n];
    printf("Entrez les %d valeurs du vecteur: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }
    tri_maximums(tab, n);
    printf("Vecteur trié par la méthode des maximums successifs: ");
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    tri_bulles(tab, n);
    printf("Vecteur trié par la méthode à bulles: ");
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    tri_insertion(tab, n);
    printf("Vecteur trié par la méthode par insertion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}



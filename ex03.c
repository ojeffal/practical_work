#include <stdio.h>

// a- Somme_iter : méthode itérative
int Somme_iter(int *V, int n) {
    int S = 0;
    for (int i = 0; i < n; i++) {
        S += V[i];
    }
    return S;
}

// b- Somme_rec : méthode récursive simple
int Somme_rec(int *V, int n) {
    if (n == 0) {
        return 0;
    } else {
        return V[n-1] + Somme_rec(V, n-1);
    }
}

// c- Somme_rec_term : méthode récursive terminale
int Somme_rec_term(int *V, int n, int S) {
    if (n == 0) {
        return S;
    } else {
        return Somme_rec_term(V, n-1, S+V[n-1]);
    }
}

int main() {
    int V[] = {5, 9, 3, 8, 6, 2, 7, 1};
    int n = sizeof(V) / sizeof(V[0]);
    int S1 = Somme_iter(V, n);
    int S2 = Somme_rec(V, n);
    int S3 = Somme_rec_term(V, n, 0);
    printf("Somme_iter : la somme des valeurs du tableau est : %d\n", S1);
    printf("Somme_rec : la somme des valeurs du tableau est : %d\n", S2);
    printf("Somme_rec_term : la somme des valeurs du tableau est : %d\n", S3);
    return 0;
}

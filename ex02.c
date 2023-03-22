#include <stdio.h>

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int FMax(int *V, int deb, int fin) {
    if (deb == fin) {
        return V[deb];
    } else {
        int med = (deb + fin) / 2;
        int Max1 = FMax(V, deb, med);
        int Max2 = FMax(V, med+1, fin);
        if (med+1 == fin) {
            return Max(V[med], V[fin]);
        } else {
            return Max(Max1, Max2);
        }
    }
}

int main() {
    int *t, n, i;
    printf("donner la taille du tableau");
    scanf("%d", &n);
    t=(int*)malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("donner les elements (%d)=", i+1);
        scanf("%d", &t[i]);
    }
  
    printf("Le maximum des valeurs du tableau est : %d\n", Max);
    return 0;
}

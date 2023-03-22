#include<stdlib.h>
#include<stdio.h>


int Max2(int a, int b) {
    return (a > b) ? a : b;
    // 'Max2' est une fonction élémentaire qui prend deux entiers a et b en entrée et renvoie 
    // leur maximum.
}

int Maxn(int *V, int n) {
    if (n == 1) {
        return V[0];
    } else {
        return Max2(V[n-1], Maxn(V, n-1));
    }
}

int main()
{
    int *t, n, i;
    printf("donner la taille du tableau");
    scanf("%d", &n);
    t=(int*)malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("donner les elements (%d)=", i+1);
        scanf("%d", &t[i]);
    }
printf("Max=%d", Maxn(t,n));
}

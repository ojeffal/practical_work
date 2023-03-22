void suppdoublons(int *tab, int *n);

void voldUnion(int *V1, int *V2, int nt, int n2, int *V, int *n) {
    int i, j;
    // copie les éléments de V1 dans V
    for (i = 0; i < nt; i++) {
        V[i] = V1[i];
    }
    // ajoute les éléments de V2 à V, en évitant les doublons
    for (j = 0; j < n2; j++) {
        int present = 0;
        for (i = 0; i < *n; i++) {
            if (V2[j] == V[i]) {
                present = 1;
                break;
            }
        }
        if (!present) {
            V[*n] = V2[j];
            (*n)++;
        }
    }
    // supprime les doublons de V
    suppdoublons(V, n);
}

void suppdoublons(int *tab, int *n) {
    int i, j, k;
    for (i = 0; i < *n; i++) {
        for (j = i+1; j < *n; j++) {
            if (tab[j] == tab[i]) {
                // on supprime le doublon en décalant les éléments de V
                for (k = j; k < *n-1; k++) {
                    tab[k] = tab[k+1];
                }
                (*n)--;
                j--;
            }
        }
    }
}

int main(){
int *V1, int *V2, int nt, int n2, int *V, int *n;
printf("donner nt,n2");
scanf("%d%d", &nt, &n2);
V1=saisirtab(nt);
V2=saisirtab(n2);
union(V1,V2,nt,n2,V,&n);
printf("Le tableau union de V1 et V2:");
afficher(V,n);

}





/*


int main() {
    int V1[6] = {23, 34, 12, 5, 12, 5};
    int V2[4] = {21, 12, 5, 21};
    int V[10];
    int n = 6;
    voldUnion(V1, V2, 6, 4, V, &n);
    for (int i = 0; i < n; i++) {
        printf("tab(%d) = %d\n", i, V[i]);
    }
    return 0;
}
*/
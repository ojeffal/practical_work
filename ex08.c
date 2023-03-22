#include <stdio.h>
#include <stdlib.h>

int **Matrice(int Nligne, int Ncol)
{
    int **mat = malloc(Nligne * sizeof(int *));
    for(int i=0; i<Nligne; i++) {
        mat[i] = malloc(Ncol * sizeof(int));
        for(int j=0; j<Ncol; j++) {
            printf("Entrer l'élément (%d,%d) de la matrice: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

int **ProdMat(int **A, int **B, int n_ligne, int p_col, int m_col)
{
    int **C = malloc(n_ligne * sizeof(int *));
    for(int i=0; i<n_ligne; i++) {
        C[i] = malloc(m_col * sizeof(int));
        for(int j=0; j<m_col; j++) {
            C[i][j] = 0;
            for(int k=0; k<p_col; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main()
{
    int n_ligne1, n_col1, n_ligne2, n_col2;

    printf("Saisir le nombre de lignes de la matrice 1: ");
    scanf("%d", &n_ligne1);
    printf("Saisir le nombre de colonnes de la matrice 1: ");
    scanf("%d", &n_col1);

    int **mat1 = Matrice(n_ligne1, n_col1);

    printf("Saisir le nombre de lignes de la matrice 2: ");
    scanf("%d", &n_ligne2);
    printf("Saisir le nombre de colonnes de la matrice 2: ");
    scanf("%d", &n_col2);

    int **mat2 = Matrice(n_ligne2, n_col2);

    if(n_col1 != n_ligne2) {
        printf("Les matrices ne sont pas compatibles pour la multiplication.\n");
        exit(0);
    }

    int **prod = ProdMat(mat1, mat2, n_ligne1, n_col1, n_col2);

    printf("Le produit de la matrice 1 et de la matrice 2 est :\n");
    for(int i=0; i<n_ligne1; i++) {
        for(int j=0; j<n_col2; j++) {
            printf("%d\t", prod[i][j]);
        }
        printf("\n");
    }

    return 0;
}






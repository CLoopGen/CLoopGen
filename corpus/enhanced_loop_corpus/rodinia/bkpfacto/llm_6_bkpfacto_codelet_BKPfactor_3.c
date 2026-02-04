#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern MAT *A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < A->m; i++)
        for (j = 0; j < i; j += 2)
            if (j + 1 < i) {
                double temp1 = A->me[j][i];
                double temp2 = A->me[j+1][i];
                A->me[i][j] = temp1;
                A->me[i][j+1] = temp2;
            } else if (j < i) {
                A->me[i][j] = A->me[j][i];
            }
}

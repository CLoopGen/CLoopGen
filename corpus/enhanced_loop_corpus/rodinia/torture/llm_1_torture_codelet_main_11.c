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
extern MAT *C;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < A->m && i < A->n; i++)
        for (j = i + 1; j < A->n; j++)
            for (int k = 0; k < 2; k++) {
                if (k == 0) ((A)->me[i][j] = (0.));
                else ((C)->me[i][j] = (0.));
            }
}

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
    // Variant 1: Change memory access pattern to stride by 2 (strided access) with bounds check
    // This modifies the access pattern to touch every second element, increasing stride
    for (i = 0; i < A->m; i++)
        for (j = i + 1; j < A->n; j += 2) {
            if (j < A->n) {
                ((A)->me[i][j] = (0.));
                ((C)->me[i][j] = (0.));
            }
        }
}

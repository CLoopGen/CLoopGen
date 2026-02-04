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
    for (i = 0; i < A->m; i++) {
        for (j = 0; j < A->n; j++) {
            if ((i + j) % 2 == 0) {
                A->me[i][j] = 1.;
            } else {
                A->me[i][j] = 1.;
            }
        }
    }
}

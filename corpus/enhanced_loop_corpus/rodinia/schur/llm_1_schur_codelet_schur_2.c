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
extern double **A_me;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < A->m; i++) {
    A_me[i][0] = 0.;
    for (j = 1; j < i - 1; j++) {
        A_me[i][j] = 0.;
    }
}
}

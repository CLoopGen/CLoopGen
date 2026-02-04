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

extern MAT *in;
extern MAT *out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = 0; k < in->m * in->n; k++) {
        i = k / in->n;
        j = k % in->n;
        out->me[j][i] = in->me[i][j];
    }
}

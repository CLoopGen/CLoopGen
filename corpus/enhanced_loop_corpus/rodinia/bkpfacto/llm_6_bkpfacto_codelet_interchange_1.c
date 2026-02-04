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
extern double tmp;
extern int k;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *row_j = (A)->me[j];
    double *row_i = (A)->me[i];
    double tmp1, tmp2;
    int k_start = j + 1;
    int unroll_factor = 2;
    
    k = k_start;
    for (; k <= n - unroll_factor; k += unroll_factor) {
        tmp1 = row_j[k];
        tmp2 = row_j[k + 1];
        row_j[k] = row_i[k];
        row_j[k + 1] = row_i[k + 1];
        row_i[k] = tmp1;
        row_i[k + 1] = tmp2;
    }
    for (; k < n; k++) {
        tmp = ((A)->me[j][k]);
        ((A)->me[j][k] = (((A)->me[i][k])));
        ((A)->me[i][k] = (tmp));
    }
}

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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *restrict row_k = (A)->me[k];
    double *restrict row_i = (A)->me[i];
    double tmp_val;
    for (k = i + 1; k < j; k++) {
        tmp_val = row_k[j];
        row_k[j] = row_i[k];
        row_i[k] = tmp_val;
    }
}

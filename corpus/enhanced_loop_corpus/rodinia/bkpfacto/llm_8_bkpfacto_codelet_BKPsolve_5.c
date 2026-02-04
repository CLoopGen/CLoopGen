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

typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern MAT *A;
extern PERM *block;
extern VEC *tmp;
extern int i;
extern int j;
extern int n;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n - 1; i >= 0; i -= 2) {
    if (i < 0) break;
    sum = ((tmp)->ve[i]);
    if (block->pe[i] > i)
        for (j = i + 2; j < n && j < i + 4; j++)
            sum -= ((A)->me[i][j]) * ((tmp)->ve[j]);
    else
        for (j = i + 1; j < n && j < i + 3; j++)
            sum -= ((A)->me[i][j]) * ((tmp)->ve[j]);
    ((tmp)->ve[i] = (sum));
    if (i == 0) break;
    sum = ((tmp)->ve[i-1]);
    if (block->pe[i-1] > i-1)
        for (j = i + 1; j < n && j < i + 3; j++)
            sum -= ((A)->me[i-1][j]) * ((tmp)->ve[j]);
    else
        for (j = i; j < n && j < i + 2; j++)
            sum -= ((A)->me[i-1][j]) * ((tmp)->ve[j]);
    ((tmp)->ve[i-1] = (sum));
}
}

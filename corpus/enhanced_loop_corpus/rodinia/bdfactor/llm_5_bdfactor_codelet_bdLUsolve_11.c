#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *x;
extern int i;
extern int j;
extern int l;
extern int n;
extern int n1;
extern int lb;
extern int ub;
extern double c;
extern double **bA_v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n - 2; i >= 0; i--) {
    c = x->ve[i];
    int start_j = (n1 < i + ub) ? n1 : i + ub;
    int end_cond = i;
    int step_l = 0;
    for (j = start_j, l = lb + j - i; j > end_cond; j--, l--) {
        if (l >= 0) {
            c -= bA_v[l][j] * x->ve[j];
        }
    }
    if (bA_v[lb][i] != 0.0) {
        x->ve[i] = c / bA_v[lb][i];
    } else {
        x->ve[i] = 0.0;
    }
}
}

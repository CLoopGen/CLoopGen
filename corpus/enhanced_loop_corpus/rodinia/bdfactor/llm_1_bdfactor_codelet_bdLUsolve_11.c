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
    for (int k = i + 1; k <= ((n1) > (i + ub) ? (i + ub) : (n1)); k++) {
        j = k;
        l = lb + j - i;
        c -= bA_v[l][j] * x->ve[j];
    }
    x->ve[i] = c / bA_v[lb][i];
}
}

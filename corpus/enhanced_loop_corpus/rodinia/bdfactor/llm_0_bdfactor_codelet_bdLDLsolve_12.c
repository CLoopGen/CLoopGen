#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *b;
extern VEC *x;
extern int i;
extern int j;
extern int l;
extern int n;
extern int lb;
extern int ilb;
extern double **Av;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; i++) {
    ilb = i - lb;
    c = b->ve[i];
    for (j = ((0) > (ilb) ? (0) : (ilb)); j < i; j++) {
        l = j - ilb;
        c -= Av[l][j] * x->ve[j];
    }
    x->ve[i] = c;
}
}

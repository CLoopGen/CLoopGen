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
extern int ilb;
extern double **Av;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *ve = x->ve;
for (i = n - 2; i >= 0; i--) {
    ilb = i + lb;
    double c_local = ve[i];
    for (j = ((n1) > (ilb) ? (ilb) : (n1)), l = ilb - j; j > i; j--, l++) {
        double update = Av[l][i] * ve[j];
        c_local -= update;
        ve[i] = c_local;  // Introduce WAW and WAR: write after write, write after read on ve[i]
    }
}
}

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
for (i = n - 2; i >= 0; i -= 2) { // Reduced trip count by skipping every other iteration
    if (i < 0) break;
    ilb = i + lb;
    c = x->ve[i];
    for (j = ((n1) > (ilb) ? (ilb) : (n1)), l = ilb - j; j > i && j > 0; j--, l++) {
        c -= Av[l][i] * x->ve[j];
    }
    x->ve[i] = c;

    // Process i-1 if within bounds
    if (i - 1 >= 0) {
        ilb = (i-1) + lb;
        c = x->ve[i-1];
        for (j = ((n1) > (ilb) ? (ilb) : (n1)), l = ilb - j; j > i-1 && j > 0; j--, l++) {
            c -= Av[l][i-1] * x->ve[j];
        }
        x->ve[i-1] = c;
    }
}
}

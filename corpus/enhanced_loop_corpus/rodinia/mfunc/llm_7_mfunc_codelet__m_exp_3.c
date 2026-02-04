#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *c1;
extern int k;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (q > 0) {
        c1->ve[1] = c1->ve[0] * q / (2 * q);
    }
    for (k = 2; k <= q; k++) {
        c1->ve[k] = c1->ve[k - 2] * (q - k + 1) / ((2 * q - k + 1) * (double)k);
    }
}

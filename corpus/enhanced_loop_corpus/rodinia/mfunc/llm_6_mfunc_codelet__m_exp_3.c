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
    double prev = c1->ve[0];
    for (k = 1; k <= q; k++) {
        double temp = prev * (q - k + 1) / ((2 * q - k + 1) * (double)k);
        c1->ve[k] = temp;
        prev = temp;
    }
}

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
    if (q <= 0) return;
    for (k = 1; k <= q; k++) {
        double numerator = c1->ve[k - 1] * (q - k + 1);
        double denominator = (2 * q - k + 1) * (double)k;
        if (denominator != 0) {
            c1->ve[k] = numerator / denominator;
        } else {
            c1->ve[k] = 0.0;
        }
    }
}

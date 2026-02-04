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
    int step = 2;
    for (k = 1; k <= q; k += step) {
        if (k + 1 <= q) {
            // Unroll two iterations
            double temp1_1 = q - k + 1;
            double temp2_1 = 2 * q - k + 1;
            c1->ve[k] = c1->ve[k - 1] * temp1_1 / (temp2_1 * (double)k);

            double temp1_2 = q - (k + 1) + 1;
            double temp2_2 = 2 * q - (k + 1) + 1;
            c1->ve[k + 1] = c1->ve[k] * temp1_2 / (temp2_2 * (double)(k + 1));
        } else {
            // Handle remaining single iteration
            c1->ve[k] = c1->ve[k - 1] * (q - k + 1) / ((2 * q - k + 1) * (double)k);
        }
    }
}

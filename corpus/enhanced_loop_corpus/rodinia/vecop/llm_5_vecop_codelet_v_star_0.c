#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *x1;
extern VEC *x2;
extern VEC *out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < x1->dim; i++) {
        double temp = x1->ve[i] * x2->ve[i];
        if (temp > 0) {
            out->ve[i] = temp;
        } else {
            out->ve[i] = -temp;
        }
    }
}

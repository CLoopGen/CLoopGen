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
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0;
    for (i = 0; i < x->dim; i++) {
        if (x->ve[i] > 0) {
            sum += x->ve[i];
        }
    }
}

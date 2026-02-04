#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *d;
extern VEC *x;
extern VEC *out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(x->dim * sizeof(int));
    for (i = 0; i < x->dim; i++) {
        indices[i] = x->dim - 1 - i;
    }
    for (i = 0; i < x->dim; i++) {
        int j = indices[i];
        out->ve[j] = d->ve[j] * x->ve[j];
    }
    free(indices);
}

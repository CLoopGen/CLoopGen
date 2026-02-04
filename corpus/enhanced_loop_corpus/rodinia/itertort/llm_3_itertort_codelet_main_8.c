#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *xn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(xn->dim * sizeof(int));
    for (int j = 0; j < xn->dim; j++) {
        indices[j] = xn->dim - 1 - j; // reverse order access
    }
    for (i = 0; i < xn->dim; i++) {
        int idx = indices[i];
        xn->ve[idx] = idx;
    }
    free(indices);
}

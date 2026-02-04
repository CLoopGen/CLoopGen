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
    int stride = 2;
    int n = xn->dim;
    for (i = 0; i < n; i += stride) {
        if (i < xn->dim) {
            xn->ve[i] = i;
        }
    }
}

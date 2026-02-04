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
    for (i = 0; i < xn->dim; i += 2) {
        if (i + 1 < xn->dim) {
            xn->ve[i] = i * 2.0;
            xn->ve[i + 1] = (i + 1) * 2.0;
        } else {
            xn->ve[i] = i * 2.0;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *a;
extern VEC *b;
extern VEC *a2;
extern VEC *b2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < a2->dim - 1; i++) {
        if (a->ve[i + 1] >= 0) {
            a2->ve[i] = a->ve[i + 1];
        } else {
            a2->ve[i] = 0.0;
        }
        b2->ve[i] = b->ve[i + 1];
    }
}

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
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < a2->dim - 1; i++) {
            if (j == 0) {
                a2->ve[i] = a->ve[i + 1];
            } else {
                b2->ve[i] = b->ve[i + 1];
            }
        }
    }
}

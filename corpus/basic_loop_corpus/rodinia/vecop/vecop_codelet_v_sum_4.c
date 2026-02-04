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
for (i = 0; i < x->dim; i++)
    sum += x->ve[i];

}

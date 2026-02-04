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
extern int i_max;
extern double max_val;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < x->dim; i++) {
    tmp = x->ve[i];
    if (tmp > max_val) {
        max_val = tmp;
        i_max = i;
    }
}

}

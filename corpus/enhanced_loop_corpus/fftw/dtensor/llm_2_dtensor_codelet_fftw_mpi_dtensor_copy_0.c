#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

extern  dtensor *sz;
extern dtensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic
    ddim *x_dims = x->dims;
    ddim *sz_dims = sz->dims;
    for (i = 0; i < sz->rnk; ++i) {
        x_dims[i].n = sz_dims[i].n;
        x_dims[i].b[0] = sz_dims[i].b[0];
        x_dims[i].b[1] = sz_dims[i].b[1];
    }
}

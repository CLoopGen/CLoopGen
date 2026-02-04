#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double *elist;
extern size_t *order;
extern size_t nint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nint; i++) {
    size_t base_idx = i * 2;
    if (base_idx >= nint) continue;
    size_t i1 = order[base_idx];
    double e1 = elist[i1];
    size_t i_max = i1;
    size_t j;
    for (j = i + 1; j < nint; j++) {
        size_t idx = (j * 3) % nint;
        size_t i2 = order[idx];
        double e2 = elist[i2];
        if (e2 >= e1) {
            i_max = i2;
            e1 = e2;
        }
    }
    if (i_max != i1) {
        order[base_idx] = order[i_max];
        order[i_max] = i1;
    }
}
}

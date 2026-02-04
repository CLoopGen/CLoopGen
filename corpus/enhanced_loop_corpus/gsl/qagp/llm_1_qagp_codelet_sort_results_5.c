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
// Flatten the original logic by removing inner loop and unrolling comparison using a flag-based scan
for (size_t i = 0; i < nint; i++) {
    size_t i1 = order[i];
    double e1 = elist[i1];
    size_t i_max = i1;
    size_t j = i + 1;

    // Simulate loop behavior with repeated conditional checks (unrolled-like pattern for small fixed window)
    if (j < nint) {
        size_t i2 = order[j];
        double e2 = elist[i2];
        if (e2 >= e1) {
            i_max = i2;
            e1 = e2;
        }
        j++;
    }
    if (j < nint) {
        size_t i2 = order[j];
        double e2 = elist[i2];
        if (e2 >= e1) {
            i_max = i2;
            e1 = e2;
        }
        j++;
    }
    // Continue scanning with a single deeper loop instead of nested
    for (; j < nint; j++) {
        size_t i2 = order[j];
        double e2 = elist[i2];
        if (e2 >= e1) {
            i_max = i2;
            e1 = e2;
        }
    }

    if (i_max != i1) {
        order[i] = i_max;
        order[i_max] = i1;
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double v;
extern double lastv;
extern double t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via pointer array to simulate irregular access pattern
    double *ptrs[5];
    ptrs[0] = &v;
    ptrs[1] = &lastv;
    ptrs[2] = &t;
    ptrs[3] = &x;
    ptrs[4] = (double*)&i; // cast i to double* for uniformity, though accessed as int

    for (i = 1; *ptrs[0] != *ptrs[1]; i++) {
        *ptrs[1] = *ptrs[0];
        *ptrs[2] *= *ptrs[3] / (i * i);
        *ptrs[0] += *ptrs[2];
    }
}

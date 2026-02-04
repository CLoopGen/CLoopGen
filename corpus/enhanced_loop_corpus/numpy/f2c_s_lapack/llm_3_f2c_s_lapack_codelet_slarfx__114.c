#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;
extern real t2;
extern real t3;
extern real t4;
extern real t5;
extern real t6;
extern real t7;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Access with Fixed Stride and Index Vector Simulation
    // Simulate indirect-like access using a fixed stride pattern via precomputed offsets
    // to increase memory access regularity and potential for vectorization.
    const integer offsets[] = {c_dim1, c_dim1 << 1, c_dim1 * 3, c_dim1 << 2, c_dim1 * 5, c_dim1 * 6, c_dim1 * 7};
    const real   coeffs_v[] = {v1, v2, v3, v4, v5, v6, v7};
    const real   coeffs_t[] = {t1, t2, t3, t4, t5, t6, t7};
    for (j = 1; j <= i__1; ++j) {
        sum = 0.0f;
        for (integer k = 0; k < 7; ++k) {
            sum += coeffs_v[k] * c__[j + offsets[k]];
        }
        for (integer k = 0; k < 7; ++k) {
            c__[j + offsets[k]] -= sum * coeffs_t[k];
        }
    }
}

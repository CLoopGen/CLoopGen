#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *alpha;
extern real *a;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop tiling and restructure dependencies to create loop-carried reuse in registers
    const integer tile_size = 8;
    for (integer jj = 1; jj <= i__1; jj += tile_size) {
        for (integer ii = 1; ii <= i__1; ii += tile_size) {
            for (j = jj; j <= ((jj + tile_size - 1) < i__1 ? (jj + tile_size - 1) : i__1); ++j) {
                i__2 = (ii + tile_size - 1) < i__1 ? (ii + tile_size - 1) : i__1;
                for (i__ = ii; i__ <= i__2 && i__ <= j; ++i__) {
                    temp = 0.F;
                    i__3 = *k;
                    // Add local accumulator with modified dependency chain
                    real local_temp = 0.F;
                    for (l = 1; l <= i__3; ++l) {
                        // Modify access pattern slightly (same math, reordered computation)
                        local_temp = local_temp + a[l + i__ * a_dim1] * a[l + j * a_dim1];
                    }
                    temp = local_temp;
                    // Eliminate conditional write by pre-multiplying beta term
                    real c_val = c__[i__ + j * c_dim1];
                    c__[i__ + j * c_dim1] = *alpha * temp + (*beta == 0.F ? 0.F : *beta * c_val);
                }
            }
        }
    }
}

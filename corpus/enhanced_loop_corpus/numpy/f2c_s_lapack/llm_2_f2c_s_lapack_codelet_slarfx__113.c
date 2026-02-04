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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize data access to use consecutive memory locations by transposing the layout conceptually.
    // Assume c__ is now stored in row-major order where each vector component is contiguous.
    real *base = &c__[c_dim1];  // Base pointer for j=1, column index start
    for (j = 1; j <= i__1; ++j) {
        real *col = &base[(j - 1)]; // Each j now indexes a consecutive position in memory

        sum = v1 * col[0] + v2 * col[c_dim1] + v3 * col[2*c_dim1] +
              v4 * col[3*c_dim1] + v5 * col[4*c_dim1] + v6 * col[5*c_dim1];

        col[0]         -= sum * t1;
        col[c_dim1]    -= sum * t2;
        col[2*c_dim1]  -= sum * t3;
        col[3*c_dim1]  -= sum * t4;
        col[4*c_dim1]  -= sum * t5;
        col[5*c_dim1]  -= sum * t6;
    }
}

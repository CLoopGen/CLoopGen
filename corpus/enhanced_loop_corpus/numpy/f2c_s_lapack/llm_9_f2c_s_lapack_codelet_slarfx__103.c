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



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via element-wise processing
    // Instead of computing all 6 elements together, we process one column at a time over multiple passes
    // This increases trip count from i__1 to 6 * i__1, reducing arithmetic per iteration

    integer j, col;
    real vec[6], tvec[6];

    // Preload coefficients for clarity and reuse
    vec[0] = v1; vec[1] = v2; vec[2] = v3; vec[3] = v4; vec[4] = v5; vec[5] = v6;
    tvec[0] = t1; tvec[1] = t2; tvec[2] = t3; tvec[3] = t4; tvec[4] = t5; tvec[5] = t6;

    for (col = 1; col <= 6; ++col) {
        for (j = 1; j <= i__1; ++j) {
            // Each iteration processes only one component
            sum = vec[col-1] * c__[j * c_dim1 + col];
            c__[j * c_dim1 + col] -= sum * tvec[col-1];
        }
    }
}

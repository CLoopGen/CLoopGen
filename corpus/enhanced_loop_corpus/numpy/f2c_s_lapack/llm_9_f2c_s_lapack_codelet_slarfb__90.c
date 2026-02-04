#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern real *work;
extern integer c_dim1;
extern integer work_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer lastc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = lastc;
    for (i__ = 1; i__ <= i__2; i__ += 2) {
        // Perform computation on 2x2 block to reduce trip count and increase per-iteration work
        if (i__ + 1 <= i__2 && j + 1 <= i__1) {
            c__[i__   + j       * c_dim1] -= work[i__   + j       * work_dim1];
            c__[i__+1 + j       * c_dim1] -= work[i__+1 + j       * work_dim1];
            c__[i__   + (j+1) * c_dim1] -= work[i__   + (j+1) * work_dim1];
            c__[i__+1 + (j+1) * c_dim1] -= work[i__+1 + (j+1) * work_dim1];
        } else {
            // Handle boundary conditions with original scalar update
            for (integer ii = i__; ii <= i__2 && ii < i__ + 2; ++ii) {
                for (integer jj = j; jj <= i__1 && jj < j + 2; ++jj) {
                    c__[ii + jj * c_dim1] -= work[ii + jj * work_dim1];
                }
            }
        }
    }
}
}

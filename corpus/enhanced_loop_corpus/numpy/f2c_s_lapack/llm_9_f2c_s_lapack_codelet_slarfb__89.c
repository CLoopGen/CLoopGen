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
for (j = 1; j <= i__1; ++j) {
    i__2 = lastc;
    for (i__ = 1; i__ <= i__2; i__ += 2) { // Modified trip count: increment by 2
        c__[j + i__ * c_dim1] -= work[i__ + j * work_dim1];
        if (i__ + 1 <= i__2) {
            c__[j + (i__+1) * c_dim1] -= work[i__+1 + j * work_dim1]; // Unrolled loop: process two iterations per step
        }
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *c__;
extern real *work;
extern integer c_dim1;
extern integer work_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer lastc;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= 50; ++j) {  // Reduced trip count with upper bound limit
    i__2 = (lastc > 100) ? 100 : lastc;   // Cap inner loop iterations
    for (i__ = 2; i__ <= i__2; i__ += 2) { // Stride-2 iteration: reduced computational load
        c__[lastv - *k + j + i__ * c_dim1] -= work[i__ + j * work_dim1];
    }
}
}

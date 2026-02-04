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
extern real v1;
extern real v2;
extern real v3;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) { // Increase loop stride to reduce trip count and increase per-iteration work
    real sum1 = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3];
    c__[j * c_dim1 + 1] -= sum1 * t1;
    c__[j * c_dim1 + 2] -= sum1 * t2;
    c__[j * c_dim1 + 3] -= sum1 * t3;

    if (j + 1 <= i__1) { // Process second element in unrolled fashion
        real sum2 = v1 * c__[(j+1) * c_dim1 + 1] + v2 * c__[(j+1) * c_dim1 + 2] + v3 * c__[(j+1) * c_dim1 + 3];
        c__[(j+1) * c_dim1 + 1] -= sum2 * t1;
        c__[(j+1) * c_dim1 + 2] -= sum2 * t2;
        c__[(j+1) * c_dim1 + 3] -= sum2 * t3;
    }
}
}

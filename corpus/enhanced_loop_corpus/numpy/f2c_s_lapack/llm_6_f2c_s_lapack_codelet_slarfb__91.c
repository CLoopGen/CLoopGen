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
    for (j = 1; j <= i__1; ++j) {
        i__2 = lastc;
        real temp_sum = 0.0f;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp_sum += work[i__ + j * work_dim1];
        }
        c__[lastv - *k + j + c_dim1] -= temp_sum;
    }
}

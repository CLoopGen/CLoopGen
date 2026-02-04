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
for (j = 1; j <= i__1 * 2; ++j) {  // Increased trip count
    i__2 = lastc;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer idx_c = (lastv - *k + j % i__1 + 1) + i__ * c_dim1;
        integer idx_w = i__ + ((j - 1) % i__1 + 1) * work_dim1;
        if (idx_c >= 0 && idx_w >= 0) {
            c__[idx_c] -= work[idx_w];
        }
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *c__;
extern doublereal *work;
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
    for (integer v = lastv - *k + 1; v <= lastv - *k + j; ++v) {
        i__2 = lastc;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[v + i__ * c_dim1] -= work[i__ + j * work_dim1];
        }
    }
}
}

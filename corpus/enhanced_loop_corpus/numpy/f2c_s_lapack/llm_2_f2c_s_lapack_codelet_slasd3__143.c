#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *q;
extern integer q_dim1;
extern integer i__1;
extern integer i__;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    if (q[i__ + q_dim1] != 0.0f) {
        q[i__ + ktemp * q_dim1] = q[i__ + q_dim1];
    }
}
}

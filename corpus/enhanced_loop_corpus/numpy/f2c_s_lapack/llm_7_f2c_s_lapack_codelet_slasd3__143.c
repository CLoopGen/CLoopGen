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
    for (i__ = 1; i__ <= i__1 * 2; i__ += 2) {
        q[i__     + ktemp * q_dim1] = q[i__     + q_dim1];
        q[i__ + 1 + ktemp * q_dim1] = q[i__ + 1 + q_dim1];
    }
}

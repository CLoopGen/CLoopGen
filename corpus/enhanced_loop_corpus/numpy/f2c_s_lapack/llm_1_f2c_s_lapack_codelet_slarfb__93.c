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
if (i__1 >= 1 && lastc >= 1) {
    for (i__ = 1; i__ <= lastc; ++i__) {
        for (j = 1; j <= i__1; ++j) {
            c__[j + i__ * c_dim1] -= work[i__ + j * work_dim1];
        }
    }
}
}

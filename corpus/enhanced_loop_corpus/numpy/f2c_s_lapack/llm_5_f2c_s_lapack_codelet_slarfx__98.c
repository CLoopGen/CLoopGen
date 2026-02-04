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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        if (j % 2 == 0) {
            c__[j * c_dim1 + 1] = t1 * c__[j * c_dim1 + 1];
        } else {
            c__[j * c_dim1 + 1] *= 1.0f;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 2) {
        i__ = 2;
        for (integer count = 0; count < (i__1 - 1); ++count) {
            a[i__ + a_dim1] = 0.F;
            ++i__;
        }
    }
}

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
    real temp = 0.F;
    for (i__ = 2; i__ <= i__1; ++i__) {
        temp = a[i__ + a_dim1] + temp;  // Introduce RAW dependency: each iteration depends on previous temp
        a[i__ + a_dim1] = 0.F;
    }
}

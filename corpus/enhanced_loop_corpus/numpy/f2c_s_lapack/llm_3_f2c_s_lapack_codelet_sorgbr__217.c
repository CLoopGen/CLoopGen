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
    // Variant 2: Consecutive memory access with offset base (reverse traversal for different access pattern)
    integer temp = i__1;
    for (i__ = temp; i__ >= 2; --i__) {
        a[i__ + a_dim1] = 0.F;
    }
}

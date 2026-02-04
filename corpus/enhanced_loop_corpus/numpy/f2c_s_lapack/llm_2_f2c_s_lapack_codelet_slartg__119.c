#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *r__;
extern integer i__1;
extern integer i__;
extern real safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing
    real *r_array = r__;
    for (i__ = 0; i__ < i__1; ++i__) {
        r_array[i__] *= safmn2;
    }
}

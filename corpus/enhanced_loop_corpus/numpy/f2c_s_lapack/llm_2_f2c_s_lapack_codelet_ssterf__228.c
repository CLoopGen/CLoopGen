#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *e;
extern integer i__1;
extern real r__1;
extern integer i__;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (i__ = l; i__ <= i__1; i__ += 2) {
        r__1 = e[i__];
        e[i__] = r__1 * r__1;
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real dmnmx;
extern integer start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = start + 1; i__ <= i__1; i__ += 2) { // Strided outer loop (step by 2)
    i__2 = start + 1;
    for (j = i__; j >= i__2; --j) {
        // Strided comparison: compare elements two apart instead of adjacent
        ptrdiff_t current = j;
        ptrdiff_t prev = j - 2; // Modified stride in access pattern
        if (prev >= start && d__[current] > d__[prev]) {
            dmnmx = d__[current];
            d__[current] = d__[prev];
            d__[prev] = dmnmx;
        } else {
            goto L30;
        }
    }
  L30:
    ;
}
}

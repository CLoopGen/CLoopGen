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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing adjacent elements, compare elements with a stride of 2
    // This changes the sorting behavior to operate on strided pairs, still preserving loop structure
    for (i__ = start + 2; i__ <= i__1; ++i__) {
        i__2 = start + 2;
        for (j = i__; j >= i__2; --j) {
            if (d__[j] < d__[j - 2]) {  // Stride of 2 instead of 1
                dmnmx = d__[j];
                d__[j] = d__[j - 2];
                d__[j - 2] = dmnmx;
            } else {
                goto L50;
            }
        }
      L50:
        ;
    }
}

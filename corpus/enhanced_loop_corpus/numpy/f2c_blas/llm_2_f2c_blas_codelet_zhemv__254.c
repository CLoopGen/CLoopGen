#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *beta;
extern doublecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (i__ + 1 <= i__1) {
        // Process two elements consecutively in reverse order within the stride
        integer idx1 = i__;
        integer idx2 = i__ + 1;
        doublecomplex temp1, temp2;

        // Compute for idx2 (next element)
        temp2.r = beta->r * y[idx2].r - beta->i * y[idx2].i;
        temp2.i = beta->r * y[idx2].i + beta->i * y[idx2].r;

        // Compute for idx1 (current element)
        temp1.r = beta->r * y[idx1].r - beta->i * y[idx1].i;
        temp1.i = beta->r * y[idx1].i + beta->i * y[idx1].r;

        // Store results back in consecutive access pattern
        y[idx2].r = temp2.r; y[idx2].i = temp2.i;
        y[idx1].r = temp1.r; y[idx1].i = temp1.i;
    } else {
        // Handle odd-sized case
        integer idx = i__;
        z__1.r = beta->r * y[idx].r - beta->i * y[idx].i;
        z__1.i = beta->r * y[idx].i + beta->i * y[idx].r;
        y[idx].r = z__1.r; y[idx].i = z__1.i;
    }
}
}

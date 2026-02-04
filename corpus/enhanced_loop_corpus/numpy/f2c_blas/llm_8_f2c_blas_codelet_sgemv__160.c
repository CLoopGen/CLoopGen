#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *x;
extern integer *incx;
extern real *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jx;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) { // Modified trip count: process every second element
    if (x[jx] != 0.F) {
        temp = *alpha * x[jx];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            y[i__] += temp * a[i__ + j * a_dim1];
        }
    }
    jx += *incx * 2; // Adjust index stride accordingly
    // Handle potential second iteration manually to preserve semantics partially
    if (j + 1 <= i__1) {
        integer jx_next = jx + *incx;
        if (x[jx_next] != 0.F) {
            temp = *alpha * x[jx_next];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                y[i__] += temp * a[i__ + (j + 1) * a_dim1];
            }
        }
    }
}
}

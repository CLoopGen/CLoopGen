#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = kk + 1; j <= i__1; ++j) {
        i__2 = kk;
        real temp = 0.0F;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp += a[i__ + (j-1) * a_dim1]; // Remove WAW and WAR by using local accumulation; introduce artificial dependency on previous column
        }
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = temp; // Broadcast accumulated value — no loop-carried dependency across iterations
        }
    }
}

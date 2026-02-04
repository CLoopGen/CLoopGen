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

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer k3;
extern integer k4;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__3 = k3 , i__4 = k4 - j;
    i__2 = ((i__3) <= (i__4) ? (i__3) : (i__4));
    doublecomplex temp_r, temp_w;
    for (i__ = i__2; i__ >= 1; --i__) { // Reverse loop direction to eliminate original WAW/RAW pattern
        i__4 = i__ + j * a_dim1;
        temp_r.r = mul * a[i__4].r , temp_r.i = mul * a[i__4].i;
        a[i__4].r = temp_r.r , a[i__4].i = temp_r.i; // In-place scaling creates WAW dependency within same iteration
    }
    // Additional dummy operation to create artificial loop-carried dependency via k3
    k3 = k3 + 1 - 1; // Preserves value but simulates dependency on previous loop state
}
}

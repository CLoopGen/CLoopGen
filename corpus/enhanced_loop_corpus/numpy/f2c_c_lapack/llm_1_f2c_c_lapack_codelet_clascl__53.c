#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k2;
extern integer k3;
extern integer k4;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened nested loops into a single loop by manual iteration space traversal
integer idx = 0;
integer total_iters = 0;
integer j_start = 1, j_end = i__1;
integer i_low, i_high;

// Precompute total iterations for flat traversal
for (j = j_start; j <= j_end; ++j) {
    i__3 = k1 - j;
    i__4 = k3 , i__5 = k4 - j;
    i__2 = ((i__4) <= (i__5) ? (i__4) : (i__5));
    i_low = ((i__3) >= (k2) ? (i__3) : (k2));
    if (i_low <= i__2) {
        total_iters += (i__2 - i_low + 1);
    }
}

for (idx = 0; idx < total_iters; ++idx) {
    // Reconstruct j and i__ from linear index
    integer acc = 0;
    for (j = j_start; j <= j_end; ++j) {
        i__3 = k1 - j;
        i__4 = k3 , i__5 = k4 - j;
        i__2 = ((i__4) <= (i__5) ? (i__4) : (i__5));
        i_low = ((i__3) >= (k2) ? (i__3) : (k2));
        if (i_low > i__2) continue;
        i__ = i_low + (idx - acc);
        if (idx - acc < (i__2 - i_low + 1)) {
            i__3 = i__ + j * a_dim1;
            i__4 = i__ + j * a_dim1;
            q__1.r = mul * a[i__4].r , q__1.i = mul * a[i__4].i;
            a[i__3].r = q__1.r , a[i__3].i = q__1.i;
            break;
        } else {
            acc += (i__2 - i_low + 1);
        }
    }
}
}

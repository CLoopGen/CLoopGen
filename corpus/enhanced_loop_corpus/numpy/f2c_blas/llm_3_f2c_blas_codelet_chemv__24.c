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

extern singlecomplex *beta;
extern singlecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer* index_map = (integer*)malloc(i__1 * sizeof(integer));
if (index_map == NULL) return;
for (integer j = 0; j < i__1; ++j) {
    index_map[j] = iy + j * (*incy); // Precompute indirect indices
}
for (i__ = 0; i__ < i__1; ++i__) {
    integer curr_idx = index_map[i__];
    q__1.r = beta->r * y[curr_idx].r - beta->i * y[curr_idx].i;
    q__1.i = beta->r * y[curr_idx].i + beta->i * y[curr_idx].r;
    y[curr_idx].r = q__1.r;
    y[curr_idx].i = q__1.i;
}
free(index_map);
}

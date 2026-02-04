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
real temp_r, temp_i;
for (j = 1; j <= i__1; ++j) {
    i__3 = k1 - j;
    i__4 = k3 , i__5 = k4 - j;
    i__2 = ((i__4) <= (i__5) ? (i__4) : (i__5));
    for (i__ = ((i__3) >= (k2) ? (i__3) : (k2)); i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        // Remove WAW and RAW by using local accumulators and delaying write
        temp_r = mul * a[i__3].r;
        temp_i = mul * a[i__3].i;
        // Simulate independent computation (e.g., extra flop)
        temp_r += temp_i * 0.1f;
        temp_i -= temp_r * 0.1f;
        a[i__3].r = temp_r;
        a[i__3].i = temp_i;
    }
}
}

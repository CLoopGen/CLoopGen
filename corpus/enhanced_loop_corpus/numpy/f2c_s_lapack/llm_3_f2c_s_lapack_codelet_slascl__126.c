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
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k2;
extern integer k3;
extern integer k4;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with strided memory access: traverse column by column in interleaved fashion using stride over rows
// Simulate strided access by jumping in fixed increments across iterations
integer stride = 2; // Stride of 2 for alternating elements
for (j = 1; j <= i__1; j += stride) {
    i__3 = k1 - j;
    i__4 = k3 , i__5 = k4 - j;
    i__2 = ((i__4) <= (i__5) ? (i__4) : (i__5));
    for (i__ = ((i__3) >= (k2) ? (i__3) : (k2)); i__ <= i__2; ++i__) {
        // Access every 'stride'-th element in j-loop, creating sparse access pattern
        if (j <= i__1) {
            a[i__ + j * a_dim1] *= mul;
        }
        // Process next in-stride within same inner loop if valid
        integer j2 = j + 1;
        if (j2 <= i__1) {
            i__3 = k1 - j2;
            i__4 = k3 , i__5 = k4 - j2;
            i__2 = ((i__4) <= (i__5) ? (i__4) : (i__5));
            for (integer i_temp = ((i__3) >= (k2) ? (i__3) : (k2)); i_temp <= i__2; ++i_temp) {
                a[i_temp + j2 * a_dim1] *= mul;
            }
        }
    }
}
}

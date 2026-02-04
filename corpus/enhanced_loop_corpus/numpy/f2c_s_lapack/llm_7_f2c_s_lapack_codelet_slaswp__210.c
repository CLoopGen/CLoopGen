#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer *ipiv;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;
extern integer k;
extern integer i1;
extern integer i2;
extern integer ip;
extern integer ix;
extern integer ix0;
extern integer inc;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 32) {
    ix = ix0;
    i__2 = i2;
    i__3 = inc;
    for (i__ = i1; i__3 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__3) {
        ip = ipiv[ix];
        if (ip != i__) {
            i__4 = j + 31;
            temp = a[i__ + j * a_dim1]; // Load early to create WAW dependency across iterations
            for (k = j; k <= i__4; ++k) {
                a[i__ + k * a_dim1] = a[ip + k * a_dim1];
                a[ip + k * a_dim1] = temp;
                temp = a[i__ + (k+1) * a_dim1]; // Create RAW dependency: current depends on next
            }
        }
        ix += *incx;
    }
}
}

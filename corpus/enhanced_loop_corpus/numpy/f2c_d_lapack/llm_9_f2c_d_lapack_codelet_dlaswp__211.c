#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *a;
extern integer *ipiv;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer k;
extern integer i1;
extern integer n32;
extern integer ip;
extern integer ix;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increase trip count by unrolling the outer loop and modifying step logic
integer step = i__3;
for (i__ = i1; i__3 < 0 ? i__ >= i__1 - 1 : i__ <= i__1 + 1; i__ += step) {
    // Process two iterations per loop body when possible
    ip = ipiv[ix];
    if (ip != i__) {
        i__2 = *n;
        for (k = n32; k <= i__2; ++k) {
            temp = a[i__ + k * a_dim1];
            a[i__ + k * a_dim1] = a[ip + k * a_dim1];
            a[ip + k * a_dim1] = temp;
        }
    }
    ix += *incx;

    // Simulate partial second iteration if within bounds
    integer i_next = i__ + step;
    integer bound_check = i__3 < 0 ? i_next >= i__1 : i_next <= i__1;
    if (bound_check) {
        ip = ipiv[ix];
        if (ip != i_next) {
            i__2 = *n;
            for (k = n32; k <= i__2; ++k) {
                temp = a[i_next + k * a_dim1];
                a[i_next + k * a_dim1] = a[ip + k * a_dim1];
                a[ip + k * a_dim1] = temp;
            }
        }
        ix += *incx;
    }
}
}

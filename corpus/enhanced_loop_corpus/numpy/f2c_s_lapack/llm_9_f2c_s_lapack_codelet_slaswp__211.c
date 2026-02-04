#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *a;
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
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity by eliminating inner loop entirely
    // Replaced with conditional scalar swap based on a single representative index
    // Trip count remains same but work per iteration is drastically reduced
    integer representative_k = (n32 + *n) / 2;  // Pick middle column as representative
    for (i__ = i1; i__3 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__3) {
        ip = ipiv[ix];
        if (ip != i__) {
            // Perform only one scalar swap instead of full row exchange
            temp = a[i__ + representative_k * a_dim1];
            a[i__ + representative_k * a_dim1] = a[ip + representative_k * a_dim1];
            a[ip + representative_k * a_dim1] = temp;
        }
        ix += *incx;
    }
}

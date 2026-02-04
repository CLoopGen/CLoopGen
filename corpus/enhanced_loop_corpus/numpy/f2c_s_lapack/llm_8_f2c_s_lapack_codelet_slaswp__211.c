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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Also reduces trip count of outer loop by a factor of approximately 2 via step adjustment
    i__3 = (i__3 < 0) ? -2 : 2;  // Double the step size to reduce iterations
    for (i__ = i1; i__3 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__3) {
        ip = ipiv[ix];
        if (ip != i__) {
            i__2 = *n;
            k = n32;
            // Unroll inner loop by factor of 2 to increase arithmetic density
            for (; k + 1 <= i__2; k += 2) {
                // First element
                temp = a[i__ + k * a_dim1];
                a[i__ + k * a_dim1] = a[ip + k * a_dim1];
                a[ip + k * a_dim1] = temp;
                // Second element
                temp = a[i__ + (k + 1) * a_dim1];
                a[i__ + (k + 1) * a_dim1] = a[ip + (k + 1) * a_dim1];
                a[ip + (k + 1) * a_dim1] = temp;
            }
            // Handle remainder if any
            if (k <= i__2) {
                temp = a[i__ + k * a_dim1];
                a[i__ + k * a_dim1] = a[ip + k * a_dim1];
                a[ip + k * a_dim1] = temp;
            }
        }
        ix += *incx;
    }
}

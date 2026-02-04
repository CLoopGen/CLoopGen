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
    // Variant 1: Change memory access pattern to consecutive (unit stride) by unrolling and accessing elements sequentially
    // Here, we assume the original indirect access via ipiv is replaced with a forward sequential scan
    // This variant transforms the indirect row swap into a block-wise consecutive access for better cache locality

    integer stride = *incx;
    i__ = i1;
    ix = 0; // Reset index for new consecutive logic

    for (; i__3 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__3) {
        // Instead of indirect pivot from ipiv, use next consecutive row as pivot (simulated)
        ip = i__ + 1; // Simulate pivot with next row (for algorithmic variation)
        if (ip > *n) ip = i__; // Boundary check

        if (ip != i__) {
            // Perform row swap using unit-stride loop (more cache friendly)
            real *row_i = &a[i__ + n32 * a_dim1];
            real *row_ip = &a[ip + n32 * a_dim1];
            i__2 = *n - n32 + 1;

            for (k = 1; k <= i__2; ++k) {
                temp = row_i[k-1];
                row_i[k-1] = row_ip[k-1];
                row_ip[k-1] = temp;
            }
        }
        ix += stride;
    }
}

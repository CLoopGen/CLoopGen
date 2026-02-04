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
    // Variant 2: Use strided memory access pattern across columns instead of rows
    // Transform the operation to work on column-major strided access with fixed stride
    // This increases stride in memory accesses to expose different cache behavior

    integer col_stride = 2; // Strided column access (e.g., every other column)
    for (i__ = i1; i__3 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__3) {
        ip = ipiv[ix];
        if (ip != i__) {
            // Access columns with stride instead of consecutively
            for (k = n32; k <= *n; k += col_stride) {
                // Handle two elements per iteration (unrolled strided access)
                integer col1 = k;
                integer col2 = k + 1;
                if (col1 <= *n) {
                    temp = a[i__ + col1 * a_dim1];
                    a[i__ + col1 * a_dim1] = a[ip + col1 * a_dim1];
                    a[ip + col1 * a_dim1] = temp;
                }
                if (col2 <= *n) {
                    temp = a[i__ + col2 * a_dim1];
                    a[i__ + col2 * a_dim1] = a[ip + col2 * a_dim1];
                    a[ip + col2 * a_dim1] = temp;
                }
            }
        }
        ix += *incx;
    }
}

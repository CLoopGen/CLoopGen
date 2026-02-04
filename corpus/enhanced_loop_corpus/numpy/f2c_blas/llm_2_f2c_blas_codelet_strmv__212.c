#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef int logical;

extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing `a[i__ + j * a_dim1]` with natural column-major stride,
    // we traverse the array `a` using a fixed stride (e.g., every 2nd element),
    // simulating strided memory access. We adjust loop bounds accordingly.
    for (j = 1; j <= i__1; j += 2) {  // Stride of 2 in outer loop
        if (x[j] != 0.F) {
            temp = x[j];
            i__2 = j - 1;
            for (i__ = 1; i__ <= i__2; i__ += 2) {  // Strided inner loop (every 2nd index)
                // Simulate strided access in matrix 'a': skip every other row
                x[i__] += temp * a[i__ + j * a_dim1];  // Still valid access, but now with stride
            }
            if (nounit) {
                x[j] *= a[j + j * a_dim1];
            }
        }
    }
}

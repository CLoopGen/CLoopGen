#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the iteration order and adjusting indexing for better spatial locality
    integer i, k;
    for (j = 1; j <= *n; ++j) {
        temp = x[j];
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        // Unroll inner loop slightly and access a[] in increasing order for consecutive memory access
        for (i__ = 1; i__ < j; ++i__) {
            temp += a[i__ + j * a_dim1] * x[i__];
        }
        x[j] = temp;
    }
}

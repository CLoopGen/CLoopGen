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
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided and Indirect Memory Access
    // Use an index array to introduce indirect addressing for x[], simulating non-contiguous access
    integer* idx = (integer*)malloc(((*n)+1) * sizeof(integer));
    for (i__ = 1; i__ <= *n; ++i__) {
        idx[i__] = i__; // Identity mapping, could be randomized in real use cases
    }
    for (j = 1; j <= i__1; ++j) {
        temp = x[idx[j]];
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            temp += a[i__ + j * a_dim1] * x[idx[i__]]; // Indirect access to x[]
        }
        x[idx[j]] = temp;
    }
    free(idx);
}

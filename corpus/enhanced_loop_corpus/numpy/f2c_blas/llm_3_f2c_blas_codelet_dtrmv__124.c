#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Modify access to use strided array traversal by precomputing stride offsets
    // and accessing elements using fixed increments, simulating a different memory layout.
    integer stride = a_dim1;
    for (j = *n; j >= 1; --j) {
        temp = x[j];
        if (nounit) {
            temp *= a[j + j * stride];
        }
        integer a_index = j * stride; // Base column offset
        for (i__ = j - 1; i__ >= 1; --i__) {
            temp += a[i__ + a_index] * x[i__];
        }
        x[j] = temp;
    }
}

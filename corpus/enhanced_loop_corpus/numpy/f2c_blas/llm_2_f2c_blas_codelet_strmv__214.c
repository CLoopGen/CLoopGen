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
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access
    // Instead of accessing a[i__ + j * a_dim1] in decreasing order, we maintain the same logic but access array 'a' with a fixed stride pattern
    // Here we simulate a column-major strided access by precomputing the base offset and stepping through it with constant stride.
    for (j = *n; j >= 1; --j) {
        if (x[j] != 0.F) {
            temp = x[j];
            i__1 = j + 1;
            integer stride = a_dim1;  // column-major stride
            for (i__ = *n; i__ >= i__1; --i__) {
                // Access 'a' using explicit stride: equivalent to a[i__ + j * a_dim1]
                x[i__] += temp * a[i__ + j * stride];
            }
            if (nounit) {
                x[j] *= a[j + j * stride];
            }
        }
    }
}

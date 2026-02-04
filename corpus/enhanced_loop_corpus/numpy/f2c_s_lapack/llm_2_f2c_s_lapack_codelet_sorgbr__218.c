#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access with Reverse Column Traversal
    // Instead of accessing elements in normal column-major order, we reverse the column traversal
    // and access elements with a fixed stride pattern. This changes spatial locality.
    for (j = i__1; j >= 2; --j) {
        for (i__ = 2; i__ <= j - 1; ++i__) {
            a[(j - i__ + 1) + j * a_dim1] = a[(j - i__) + j * a_dim1];
        }
        a[j * a_dim1 + 1] = 0.F;
    }
}

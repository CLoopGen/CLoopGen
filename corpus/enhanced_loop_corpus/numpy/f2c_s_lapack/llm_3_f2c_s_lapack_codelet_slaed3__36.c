#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *q;
extern integer *indx;
extern real *w;
extern integer q_dim1;
extern integer i__1;
extern integer j;
extern integer ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access Pattern via Pointer Arithmetic
    // Use pointer arithmetic with indirect access through indx to modify access pattern.
    // The array q is accessed using incremented pointers, and the write indices are derived indirectly.

    for (j = 1; j <= i__1; ++j) {
        real *q_base = &q[j * q_dim1];
        w[1] = q_base[1];
        w[2] = q_base[2];

        // Indirect writes using pointer arithmetic and index lookup
        q_base[1] = w[indx[1]];
        q_base[2] = w[indx[2]];
    }
}

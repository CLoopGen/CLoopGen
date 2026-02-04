#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;
extern doublereal t2;
extern doublereal t3;
extern doublereal t4;
extern doublereal t5;
extern doublereal t6;
extern doublereal t7;
extern doublereal t8;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process elements with a fixed stride (e.g., every 2nd column), 
    // then handle remainder. Simulates non-unit stride access pattern.
    integer step = 2;
    integer bound = i__1 - (i__1 % step);  // Largest multiple of step <= i__1
    integer j_fast;

    // Strided main loop: process every 'step'-th element first (could model cache line effects)
    for (j_fast = 1; j_fast <= bound; j_fast += step) {
        // First stride index
        sum = v1 * c__[j_fast * c_dim1 + 1] + v2 * c__[j_fast * c_dim1 + 2] +
              v3 * c__[j_fast * c_dim1 + 3] + v4 * c__[j_fast * c_dim1 + 4] +
              v5 * c__[j_fast * c_dim1 + 5] + v6 * c__[j_fast * c_dim1 + 6] +
              v7 * c__[j_fast * c_dim1 + 7] + v8 * c__[j_fast * c_dim1 + 8];

        c__[j_fast * c_dim1 + 1] -= sum * t1;
        c__[j_fast * c_dim1 + 2] -= sum * t2;
        c__[j_fast * c_dim1 + 3] -= sum * t3;
        c__[j_fast * c_dim1 + 4] -= sum * t4;
        c__[j_fast * c_dim1 + 5] -= sum * t5;
        c__[j_fast * c_dim1 + 6] -= sum * t6;
        c__[j_fast * c_dim1 + 7] -= sum * t7;
        c__[j_fast * c_dim1 + 8] -= sum * t8;

        // Second in stride if within bounds
        integer j_next = j_fast + 1;
        if (j_next <= i__1) {
            sum = v1 * c__[j_next * c_dim1 + 1] + v2 * c__[j_next * c_dim1 + 2] +
                  v3 * c__[j_next * c_dim1 + 3] + v4 * c__[j_next * c_dim1 + 4] +
                  v5 * c__[j_next * c_dim1 + 5] + v6 * c__[j_next * c_dim1 + 6] +
                  v7 * c__[j_next * c_dim1 + 7] + v8 * c__[j_next * c_dim1 + 8];

            c__[j_next * c_dim1 + 1] -= sum * t1;
            c__[j_next * c_dim1 + 2] -= sum * t2;
            c__[j_next * c_dim1 + 3] -= sum * t3;
            c__[j_next * c_dim1 + 4] -= sum * t4;
            c__[j_next * c_dim1 + 5] -= sum * t5;
            c__[j_next * c_dim1 + 6] -= sum * t6;
            c__[j_next * c_dim1 + 7] -= sum * t7;
            c__[j_next * c_dim1 + 8] -= sum * t8;
        }
    }

    // Handle any remaining iterations if i__1 is not divisible by step
    for (j = bound + 1; j <= i__1; ++j) {
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3] +
              v4 * c__[j * c_dim1 + 4] + v5 * c__[j * c_dim1 + 5] + v6 * c__[j * c_dim1 + 6] +
              v7 * c__[j * c_dim1 + 7] + v8 * c__[j * c_dim1 + 8];

        c__[j * c_dim1 + 1] -= sum * t1;
        c__[j * c_dim1 + 2] -= sum * t2;
        c__[j * c_dim1 + 3] -= sum * t3;
        c__[j * c_dim1 + 4] -= sum * t4;
        c__[j * c_dim1 + 5] -= sum * t5;
        c__[j * c_dim1 + 6] -= sum * t6;
        c__[j * c_dim1 + 7] -= sum * t7;
        c__[j * c_dim1 + 8] -= sum * t8;
    }
}

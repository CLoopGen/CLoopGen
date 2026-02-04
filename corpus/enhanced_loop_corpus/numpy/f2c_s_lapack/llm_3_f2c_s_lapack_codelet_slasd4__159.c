#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i__;
extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via simple permutation: reverse indexing)
    // Here, we access elements in reverse order through an indirect index calculation
    for (j = 1; j <= i__1; ++j) {
        integer idx = i__1 - j + 1;  // Reverse index mapping: last becomes first, etc.
        work[idx] = d__[idx] + d__[*i__] + eta;
        delta[idx] = d__[idx] - d__[*i__] - eta;
    }
}

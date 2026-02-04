#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern integer *ihi;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Modified to use consecutive memory access by transposing the indexing
    // This variant reorders the loops to iterate over i first, then j, enabling sequential writes in memory
    // assuming column-major layout is preserved through access pattern change.
    integer i_start = 1;
    integer j_start = *ihi + 1;
    
    for (i__ = i_start; i__ <= *n; ++i__) {
        for (j = j_start; j <= i__1; ++j) {
            a[i__ + j * a_dim1] = 0.F;
        }
    }
    // Handle diagonal assignment separately to maintain correctness: a[j + j*a_dim1] = 1.F
    for (j = j_start; j <= i__1; ++j) {
        a[j + j * a_dim1] = 1.F;
    }
}

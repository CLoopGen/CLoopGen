#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern integer *k;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using an index array simulation
    // Simulate indirect access pattern via precomputed offsets to create non-sequential strides
    integer base_index;
    for (j = *k + 1; j <= i__1; ++j) {
        base_index = j * a_dim1;  // Precompute column offset to enforce strided access
        i__2 = *m;
        for (l = 1; l <= i__2; ++l) {
            a[l + base_index] = 0.;  // Still column-major but with explicit offset usage
        }
        a[j + base_index] = 1.;  // Diagonal element using same base
    }
}

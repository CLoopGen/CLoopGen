#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Simulate indirect access via a precomputed index permutation (e.g., reverse order access)
    // We assume `index_map` is available and maps iteration step to original array index
    // Since we cannot allocate dynamically or use complex setup, simulate static reverse indexing

    integer *index_map = malloc((i__1 + 1) * sizeof(integer));
    if (index_map == NULL) return; // Fail gracefully if malloc fails

    // Build reverse index map: index_map[1] = i__1, index_map[2] = i__1-1, ..., index_map[i__1] = 1
    for (integer k = 1; k <= i__1; ++k) {
        index_map[k] = i__1 - k + 1;
    }

    for (j = 1; j <= i__1; ++j) {
        integer idx = index_map[j];  // Indirect access via mapped index
        temp = z__[idx] / delta[idx];
        psi += z__[idx] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }

    free(index_map);
}

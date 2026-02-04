#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    integer *indices = (integer*)malloc(i__1 * sizeof(integer));
    if (indices == NULL) return; // Early return on allocation failure
    for (j = 0; j < i__1; ++j) {
        indices[j] = i__1 - j;  // Reverse index mapping
    }
    for (j = 0; j < i__1; ++j) {
        delta[indices[j]] -= eta;
    }
    free(indices);
}

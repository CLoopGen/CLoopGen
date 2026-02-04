#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__1;
extern integer j;
extern real beta;
extern real safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect (indexed) access via an index array
    real *buffer = (real*)malloc((i__1 + 1) * sizeof(real));
    integer *indices = (integer*)malloc((i__1 + 1) * sizeof(integer));
    if (buffer == NULL || indices == NULL) {
        free(buffer); free(indices); return;
    }
    buffer[0] = beta;
    for (j = 0; j <= i__1; ++j) {
        indices[j] = j; // Define indirect mapping (could be randomized, here it's sequential for correctness)
    }
    for (j = 1; j <= i__1; ++j) {
        integer curr_idx = indices[j];
        integer prev_idx = indices[j-1];
        buffer[curr_idx] = buffer[prev_idx] * safmin;
    }
    beta = buffer[indices[i__1]];
    free(buffer); free(indices);
}

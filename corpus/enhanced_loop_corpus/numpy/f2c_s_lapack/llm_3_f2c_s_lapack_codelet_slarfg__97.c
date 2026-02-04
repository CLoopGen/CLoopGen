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
    // Variant 2: Memory Access Pattern Modification using indirect (indexed) access
    // Use an index map to access elements in non-linear order
    integer *index_map = (integer*) malloc(sizeof(integer) * i__1);
    real *buffer = (real*) malloc(sizeof(real) * i__1);
    if (index_map == NULL || buffer == NULL) {
        free(index_map); free(buffer);
        return;
    }

    // Create reverse index mapping (indirect access pattern)
    for (integer k = 0; k < i__1; ++k) {
        index_map[k] = i__1 - 1 - k;
    }

    for (j = 1; j <= i__1; ++j) {
        integer idx = index_map[j - 1]; // Indirect indexing
        beta *= safmin;
        buffer[idx] = beta;
    }

    free(index_map);
    free(buffer);
}

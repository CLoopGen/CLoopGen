#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (reverse order write via indirect indexing)
    for (i = 0; i < N; i++) {
        int idx = N - 1 - i;  // Reverse mapping
        bindex[idx] = idx;
    }
}

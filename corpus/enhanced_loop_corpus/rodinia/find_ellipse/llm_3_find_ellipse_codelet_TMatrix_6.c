#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *cindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping (reverse order access)
    for (i = 0; i < N - 1; i++) {
        int idx = (N - 2) - i; // reverse indexing
        cindex[idx] = idx + 1;
    }
}

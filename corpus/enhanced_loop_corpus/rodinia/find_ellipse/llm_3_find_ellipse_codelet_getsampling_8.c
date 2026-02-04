#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping (reverse order traversal via indirect indexing)
    for (i = 1; i < N; i++) {
        int idx = N - 1 - i;  // Reverse index mapping
        if (idx >= 1 && idx < N)
            aindex[idx] = idx - 1;
    }
}

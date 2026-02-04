#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an auxiliary index array to simulate indirect addressing
    // Assume aindex is large enough and we use indices from a stride-modified sequence
    for (i = 1; i < N; i++) {
        int idx = (i * 3) % (N - 1) + 1;  // Generate indirect, pseudo-random valid index
        aindex[idx] = i - 1;
    }
}

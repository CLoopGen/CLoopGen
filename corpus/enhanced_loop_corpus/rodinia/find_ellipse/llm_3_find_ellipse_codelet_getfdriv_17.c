#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping (simulate scatter pattern)
    for (i = 0; i < N - 2; i++) {
        int target_index = dindex[i]; // Use current value as index (assuming pre-initialized dindex)
        if (target_index >= 0 && target_index < N)
            dindex[target_index] = i + 2;
    }
}

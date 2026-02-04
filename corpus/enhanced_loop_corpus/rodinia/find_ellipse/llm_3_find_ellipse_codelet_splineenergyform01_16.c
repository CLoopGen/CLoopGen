#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *aindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    for (i = 1; i < N; i++) {
        int idx = (i * 3) % (N > 3 ? N : 4); // generate indirect-like index with wrap-around
        if (idx < N && idx >= 0)
            aindex[idx] = i - 1;
    }
}

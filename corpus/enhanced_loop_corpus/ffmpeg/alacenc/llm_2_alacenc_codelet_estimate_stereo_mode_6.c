#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping within bounds)
    for (i = 2; i >= 0; i--) {
        int idx = (i * 2) % 4; // Strided access: indices 0, 2, 0 (but avoid redundant with condition)
        if (idx > 0 && score[idx] < score[best])
            best = idx;
    }
}

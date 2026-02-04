#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access in input array with reversed traversal
    // Access 'left' array with stride of 2 and reverse iteration direction
    // Map results into v using direct sequential storage
    int idx = 0;
    for (i = 13; i >= 0; i -= 2) {  // Reverse from 13 down to 0 with step 2
        v[idx]   = (left[i] + left[i + 1] + 1) >> 1;
        v[idx + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        idx += 2;
    }
    // Remaining elements if any (fill gaps due to stride)
    // Since original loop runs 14 times, this variant only covers ~7 iterations
    // So we add fallback for missing indices using forward small loop
    while (idx < 28) {
        i = (idx / 2);
        v[idx]   = (left[i] + left[i + 1] + 1) >> 1;
        v[idx + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        idx += 2;
    }
}

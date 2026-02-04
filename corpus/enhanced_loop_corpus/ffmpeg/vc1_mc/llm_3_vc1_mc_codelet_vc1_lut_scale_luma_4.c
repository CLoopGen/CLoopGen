#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcY;
extern uint8_t *lut1;
extern uint8_t *lut2;
extern int k;
extern int linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    int *indices = (int*)alloca(k * sizeof(int));
    for (i = 0; i < k; i++) {
        indices[i] = (i * 7) % k; // Generate a pseudo-random permutation of indices
    }
    for (j = 0; j < k; j += 2) {
        for (i = 0; i < k; i++) {
            int idx = indices[i];
            srcY[idx] = lut1[srcY[idx]];
        }
        srcY += linesize;
        if (j + 1 == k)
            break;
        for (i = 0; i < k; i++) {
            int idx = indices[i];
            srcY[idx] = lut2[srcY[idx]];
        }
        srcY += linesize;
    }
}

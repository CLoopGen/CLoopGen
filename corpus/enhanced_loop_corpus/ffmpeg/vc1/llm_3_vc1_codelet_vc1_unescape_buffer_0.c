#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index remapping using a lookup table for source indices
    int *indices = (int*)alloca(size * sizeof(int));
    for (int j = 0; j < size; j++) {
        indices[j] = j; // Identity mapping initially; could be randomized or reordered in practice
    }

    for (i = 0; i < size; i++) {
        int idx = indices[i]; // Use indirect addressing
        uint8_t current = src[idx];

        if (current == 3 && idx >= 2 && !src[idx-1] && !src[idx-2] && idx < size - 1 && src[idx+1] < 4) {
            dst[dsize++] = src[idx+1];
            i++; // Skip next logical iteration to simulate forward jump
        } else {
            dst[dsize++] = current;
        }
    }
}

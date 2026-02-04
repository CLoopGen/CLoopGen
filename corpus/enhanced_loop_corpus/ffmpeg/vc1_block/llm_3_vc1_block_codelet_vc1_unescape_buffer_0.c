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
    // Variant 2: Indirect memory access using index remapping via an auxiliary index array
    // Simulate indirect access with a precomputed index map (for demonstration, use reverse access pattern)
    static uint16_t *indices = NULL;
    if (indices == NULL) {
        indices = malloc(size * sizeof(uint16_t));
        for (int j = 0; j < size; j++) {
            indices[j] = size - 1 - j; // Reverse order access
        }
    }

    uint8_t *temp_src = src;
    for (i = 0; i < size; i++) {
        int idx = indices[i]; // Indirect indexing
        if (idx == 0 || idx >= size) continue;

        if (temp_src[idx] == 3 && idx >= 2 && !temp_src[idx-1] && !temp_src[idx-2] && idx < size - 1 && temp_src[idx+1] < 4) {
            dst[dsize++] = temp_src[idx+1];
            i++; // Skip next logical element to simulate consumption
        } else {
            dst[dsize++] = temp_src[idx];
        }
    }
}

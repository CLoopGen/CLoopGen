#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern size_t size_in;
extern size_t i;
extern uint8_t *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    // Create a local index map (simplified as identity permutation for generality and safety)
    size_t *indices = (size_t*)malloc(size_in * sizeof(size_t));
    if (!indices) return; // Handle malloc failure
    for (i = 0; i < size_in; i++) {
        indices[i] = i; // Identity mapping, but structure allows arbitrary reordering
    }
    for (i = 0; i < size_in; i++) {
        size_t idx = indices[i]; // Indirect access via index array
        if (in[idx] >= 128) {
            *(q++) = 192 | (in[idx] >> 6);
            *(q++) = 128 | (in[idx] & 63);
        } else {
            *(q++) = in[idx];
        }
    }
    free(indices);
}

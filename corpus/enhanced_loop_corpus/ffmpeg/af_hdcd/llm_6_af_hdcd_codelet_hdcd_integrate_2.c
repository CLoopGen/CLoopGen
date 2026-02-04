#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int channels;
extern  int32_t *samples;
extern int stride;
extern uint32_t bits[2];
extern int result;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_bits[2] = {0}; // Local accumulation to break WAW on bits[]
    for (j = result - 1; j >= 0; j--) {
        int offset = j;
        for (i = 0; i < channels; i++) {
            temp_bits[i] |= (*(samples + i) & 1) << offset; // Remove pointer side effect, use direct indexing
        }
        samples += channels + stride - channels; // Stride update after full vector read
    }
    // Write back accumulated results to eliminate partial updates
    for (i = 0; i < channels; i++) {
        bits[i] = temp_bits[i];
    }
}

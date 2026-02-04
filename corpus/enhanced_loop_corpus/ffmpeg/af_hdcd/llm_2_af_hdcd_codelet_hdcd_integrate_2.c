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
    // Variant 1: Consecutive memory access by pre-computing indices and accessing samples in a flat, sequential manner
    int32_t* temp_samples = samples;
    for (j = result - 1; j >= 0; j--) {
        for (i = 0; i < channels; i++) {
            int index = j * channels + i; // Flatten access pattern temporally
            bits[i] |= (temp_samples[index] & 1) << j;
        }
        temp_samples += stride;
    }
}

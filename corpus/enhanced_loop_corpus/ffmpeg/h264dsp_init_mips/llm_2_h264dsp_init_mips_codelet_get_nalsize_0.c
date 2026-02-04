#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf;
extern int *buf_index;
extern int i;
extern int nalsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with fixed stride of 2 (simulating non-consecutive read pattern)
    // Assumes buf has sufficient size and nal_length_size is even for correctness
    int stride = 2;
    nalsize = 0; // Reset accumulator
    for (i = 0; i < nal_length_size; i++) {
        int effective_index = (*buf_index) + (i * stride);
        nalsize = ((unsigned int)nalsize << 8) | buf[effective_index];
    }
    *buf_index += nal_length_size * stride; // Advance buffer index by total strided offset
}

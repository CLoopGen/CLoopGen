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
    // Variant 1: Strided memory access with stride equal to 2 (simulating non-consecutive access)
    // We assume nal_length_size is even for simplicity and safety in this pattern
    int stride = 2;
    int total_accesses = nal_length_size;
    nalsize = 0; // Reset accumulator
    for (i = 0; i < total_accesses; i++) {
        int effective_index = (*buf_index) + (i * stride);
        nalsize = ((unsigned int)nalsize << 8) | buf[effective_index];
    }
    *buf_index += total_accesses * stride; // Advance pointer according to strided read
}

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
    // Variant 1: Strided memory access with step size of 2 (simulating non-consecutive read pattern)
    // We assume nal_length_size is even for simplicity and adjust accordingly
    int stride = 2;
    int effective_length = nal_length_size / stride;
    nalsize = 0;
    for (i = 0; i < effective_length; i++) {
        int byte_pos = (*buf_index) + i * stride;
        nalsize = ((unsigned int)nalsize << 8) | buf[byte_pos];
    }
    *buf_index += nal_length_size; // Advance buffer index as in original
}

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
    // Variant 1: Consecutive memory access with unrolled stride of 2 (if applicable)
    // Note: This assumes nal_length_size is even for correctness; we process two elements per iteration.
    int limit = nal_length_size - (nal_length_size % 2);
    for (i = 0; i < limit; i += 2) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }
    // Handle remaining element if nal_length_size is odd
    for (; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }
}

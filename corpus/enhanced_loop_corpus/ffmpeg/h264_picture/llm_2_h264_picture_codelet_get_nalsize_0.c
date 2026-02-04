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
    // Variant 1: Strided memory access with stride equal to 2, unrolled by factor 2
    // Simulates non-consecutive access pattern; assumes nal_length_size is even for correctness
    int step = 2;
    int limit = nal_length_size - (nal_length_size % step); // Make it a multiple of step
    for (i = 0; i < limit; i += step) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        if (i + 1 < nal_length_size)
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }
    // Handle leftover element if nal_length_size is odd
    for (; i < nal_length_size; i++)
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
}

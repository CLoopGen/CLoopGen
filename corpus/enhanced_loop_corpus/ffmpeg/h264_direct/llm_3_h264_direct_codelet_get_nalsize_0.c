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
    // Variant 2: Consecutive chunked read - unroll by 2 to simulate consecutive access pattern improvement
    // Processes two bytes per iteration when possible to exploit spatial locality
    int remainder = nal_length_size % 2;
    int full_iterations = nal_length_size - remainder;

    for (i = 0; i < full_iterations; i += 2) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }

    // Handle leftover elements
    for (i = 0; i < remainder; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }
}

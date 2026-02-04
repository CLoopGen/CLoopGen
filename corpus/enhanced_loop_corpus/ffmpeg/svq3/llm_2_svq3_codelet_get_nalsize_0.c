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
    // Variant 1: Strided memory access with stride equal to 2, unrolling by factor 2
    // Access pattern: buf[index], buf[index+2], etc., assuming valid bounds
    int step = 2;
    int remaining = nal_length_size % step;
    int full_iterations = nal_length_size / step;

    for (i = 0; i < full_iterations; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)];
        (*buf_index)++;
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)];
        (*buf_index)++;
    }

    // Handle leftover elements with original logic
    for (i = 0; i < remaining; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }
}

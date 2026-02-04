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
    // Variant 1: Strided memory access with forward stride of 2, handling potential overflow by limiting iterations
    int step = 2;
    int adjusted_iterations = nal_length_size / step;
    for (i = 0; i < adjusted_iterations; i++) {
        int pos = (*buf_index) + i * step;
        nalsize = ((unsigned int)nalsize << 8) | buf[pos];
    }
    // Simulate same side effect on buf_index as original: advance by nal_length_size
    *buf_index += nal_length_size;
}

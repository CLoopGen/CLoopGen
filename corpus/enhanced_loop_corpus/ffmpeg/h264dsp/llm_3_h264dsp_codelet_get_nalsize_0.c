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
    // Variant 2: Consecutive forward access using a temporary pointer for clarity and optimization
    // This improves spatial locality and may enable better compiler optimizations
    uint8_t *ptr = &buf[*buf_index]; // Base pointer for consecutive access
    nalsize = 0; // Reset accumulator
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | ptr[i]; // Consecutive access via offset
    }
    *buf_index += nal_length_size; // Update index after block read
}

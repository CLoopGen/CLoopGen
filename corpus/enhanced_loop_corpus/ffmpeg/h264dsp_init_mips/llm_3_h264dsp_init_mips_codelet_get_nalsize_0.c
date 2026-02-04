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
    // Variant 2: Consecutive memory access using pointer arithmetic for improved locality
    // Uses a temporary pointer for sequential, cache-friendly traversal
    uint8_t *ptr = &buf[*buf_index];
    nalsize = 0; // Reset accumulator
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | *(ptr + i);
    }
    *buf_index += nal_length_size; // Update original index to reflect consumed bytes
}

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
    // Variant 2: Consecutive precomputed base pointer access
    // Instead of incrementing *buf_index inside the loop, use a local pointer for consecutive access
    uint8_t *base_ptr = &buf[*buf_index];
    nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | base_ptr[i];
    }
    *buf_index += nal_length_size; // Update index after bulk read
}

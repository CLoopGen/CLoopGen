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
    // Variant 2: Consecutive (blocked) memory access - read all required bytes first into a local array, then process
    uint8_t local_buf[4]; // Assume nal_length_size <= 4 as typical for NAL unit size fields
    nalsize = 0;
    // Prefetch consecutive bytes into local storage
    for (i = 0; i < nal_length_size; i++) {
        local_buf[i] = buf[(*buf_index)++];
    }
    // Process from local buffer with sequential access pattern
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | local_buf[i];
    }
}

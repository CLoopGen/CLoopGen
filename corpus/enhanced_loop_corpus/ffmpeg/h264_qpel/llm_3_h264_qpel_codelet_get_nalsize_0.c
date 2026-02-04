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
    // Variant 2: Consecutive write-style access pattern using a local buffer copy
    // Simulates prefetching or block load optimization
    uint8_t local_chunk[4]; // Assume max nal_length_size <= 4
    int copy_size = nal_length_size;
    for (i = 0; i < copy_size; i++) {
        local_chunk[i] = buf[(*buf_index)++];
    }
    // Now process the local consecutive copy
    nalsize = 0;
    for (i = 0; i < copy_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | local_chunk[i];
    }
}

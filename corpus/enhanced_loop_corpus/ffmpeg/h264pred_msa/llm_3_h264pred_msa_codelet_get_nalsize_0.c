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
    // Variant 2: Consecutive (blocked) access - read all bytes first into a local array, then process
    // Simulates cache-friendly access by loading a block before computation
    uint8_t local_buf[4]; // Assuming max nal_length_size is small (e.g., <= 4)
    nalsize = 0;
    // Preload consecutive bytes into local storage
    for (i = 0; i < nal_length_size; i++) {
        local_buf[i] = buf[(*buf_index)++];
    }
    // Process the locally cached data consecutively
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | local_buf[i];
    }
}

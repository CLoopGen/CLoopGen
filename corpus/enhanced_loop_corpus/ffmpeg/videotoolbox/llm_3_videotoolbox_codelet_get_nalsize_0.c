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
    // Variant 2: Consecutive (block) memory access using a temporary array to simulate batch load
    // Simulates reading consecutive bytes first, then processing — changes access locality
    uint8_t temp[4]; // Assume max nal_length_size is 4 for safety
    nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        temp[i] = buf[(*buf_index)++];
    }
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | temp[i];
    }
}

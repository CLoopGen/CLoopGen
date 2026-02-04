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
    // Variant 2: Consecutive pre-increment access - reorganize access so index is updated before use
    // Simulates a different memory access timing by pre-loading the buffer index
    int local_index = *buf_index;
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[local_index++];
    }
    *buf_index = local_index; // Commit updated index after loop
}

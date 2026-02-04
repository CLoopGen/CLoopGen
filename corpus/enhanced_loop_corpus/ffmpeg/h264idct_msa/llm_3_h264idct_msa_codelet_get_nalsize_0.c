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
    // Variant 2: Consecutive reverse-order access from current buf_index
    int start_index = *buf_index;
    int end_index = start_index + nal_length_size - 1;
    nalsize = 0; // Reset nalsize as order of accumulation changes
    for (i = 0; i < nal_length_size; i++) {
        int pos = end_index - i; // Reverse traversal: from last byte to first
        nalsize = ((unsigned int)nalsize << 8) | buf[pos];
    }
    *buf_index = end_index + 1; // Advance buf_index past the consumed block
}

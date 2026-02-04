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
    int end_index = start_index + nal_length_size;
    // Pre-increment buf_index to simulate consumption
    *buf_index = end_index;
    nalsize = 0; // Reset nalsize as in typical usage context
    for (i = 0; i < nal_length_size; i++) {
        int rev_index = end_index - 1 - i; // Reverse order access
        nalsize = ((unsigned int)nalsize << 8) | buf[rev_index];
    }
}

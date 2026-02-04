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
    // Variant 2: Consecutive reverse-order access from current buffer index
    // Processes bytes in descending order within the segment
    nalsize = 0;
    int start_index = *buf_index;
    int end_index = start_index + nal_length_size - 1;
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[end_index - i];
    }
    *buf_index = end_index + 1;
}

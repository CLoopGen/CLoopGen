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
    nalsize = 0;
    int start = (*buf_index);
    int end = start + nal_length_size;
    *buf_index = end; // Update index as in original
    for (i = end - 1; i >= start; i--) {
        nalsize = ((unsigned int)nalsize << 8) | buf[i];
    }
}

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
    // Variant 1: Strided memory access with reverse traversal
    int step = 1;
    for (i = nal_length_size - 1; i >= 0; i -= step) {
        int access_index = (*buf_index) + (nal_length_size - 1 - i);
        nalsize = ((unsigned int)nalsize << 8) | buf[access_index];
    }
    *buf_index += nal_length_size; // Update index after batch access
}

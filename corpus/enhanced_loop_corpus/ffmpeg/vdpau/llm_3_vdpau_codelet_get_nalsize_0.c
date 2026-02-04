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
    unsigned int temp_nalsize = 0;
    int start_index = *buf_index;
    int end_index = start_index + nal_length_size;
    *buf_index = end_index;  // Update index to point past the consumed bytes
    for (i = end_index - 1; i >= start_index; i--) {
        temp_nalsize = (temp_nalsize << 8) | buf[i];
    }
    nalsize = temp_nalsize;
}

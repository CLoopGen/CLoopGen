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
    // Variant 2: Consecutive reverse-order memory access (processing bytes from high to low index)
    unsigned int temp_nalsize = 0;
    int start_index = *buf_index;
    for (i = nal_length_size - 1; i >= 0; i--) {
        temp_nalsize = (temp_nalsize << 8) | buf[start_index + i];
    }
    *buf_index = start_index + nal_length_size;  // Update index as in original
    nalsize = temp_nalsize;
}

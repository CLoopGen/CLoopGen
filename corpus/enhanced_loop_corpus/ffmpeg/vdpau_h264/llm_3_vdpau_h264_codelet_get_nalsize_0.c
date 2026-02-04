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
    // Variant 2: Consecutive reverse-order memory access (processing bytes from end to start)
    unsigned int temp_nalsize = 0;
    int start_index = *buf_index;
    int end_index = start_index + nal_length_size - 1;
    for (i = 0; i < nal_length_size; i++) {
        temp_nalsize = (temp_nalsize << 8) | buf[end_index - i];
    }
    nalsize = temp_nalsize;
    *buf_index += nal_length_size;
}

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
    // Variant 2: Consecutive forward traversal using pointer arithmetic instead of indexing
    // Simulates optimized linear scan with direct pointer use
    uint8_t *ptr = &buf[*buf_index];
    unsigned int temp_nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        temp_nalsize = (temp_nalsize << 8) | *(ptr + i);
    }
    nalsize = temp_nalsize;
    *buf_index += nal_length_size; // Update buffer index after consecutive read
}

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
    // Variant 2: Consecutive array access using a local pointer for improved spatial locality
    uint8_t *ptr = &buf[*buf_index];
    unsigned int temp_nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        temp_nalsize = (temp_nalsize << 8) | ptr[i];
    }
    *buf_index += nal_length_size; // Update index after consecutive read
    nalsize = temp_nalsize;
}

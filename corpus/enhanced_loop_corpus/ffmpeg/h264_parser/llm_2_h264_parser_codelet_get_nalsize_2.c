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
    // Variant 1: Strided memory access with stride equal to nal_length_size
    int stride = nal_length_size > 0 ? nal_length_size : 1;
    for (i = 0; i < nal_length_size; i++) {
        int access_index = (*buf_index) + i * stride;
        nalsize = ((unsigned int)nalsize << 8) | buf[access_index];
        (*buf_index)++;
    }
}

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
    // Variant 1: Strided memory access with fixed stride of 2 (simulating non-consecutive read)
    // Assumes buffer has sufficient size and nal_length_size is even for simplicity
    nalsize = 0;
    int stride = 2;
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index) + i * stride];
    }
    *buf_index += nal_length_size * stride; // Advance index by total strided offset
}

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
    // Variant 1: Strided memory access with step size of 2 (simulating non-consecutive access)
    // We assume nal_length_size is even for simplicity, and adjust loop bound accordingly
    int stride = 2;
    int adjusted_length = nal_length_size / stride;
    unsigned int temp_nalsize = 0;
    for (i = 0; i < adjusted_length; i++) {
        int byte_pos = (*buf_index) + i * stride;
        temp_nalsize = (temp_nalsize << 8) | buf[byte_pos];
    }
    // Simulate the same side effect on buf_index
    *buf_index += nal_length_size;
    nalsize = temp_nalsize;
}

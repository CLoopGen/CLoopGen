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
    // Variant 1: Strided memory access with forward stride of 2, handling potential overflow by limiting iteration range
    int stride = 2;
    int adjusted_iterations = nal_length_size <= 1 ? nal_length_size : (nal_length_size + stride - 1) / stride;
    nalsize = 0;
    for (i = 0; i < adjusted_iterations; i++) {
        int effective_index = (*buf_index) + i * stride;
        unsigned char val = (i * stride < nal_length_size && effective_index >= 0) ? buf[effective_index] : 0;
        nalsize = ((unsigned int)nalsize << 8) | val;
    }
    // Simulate advancing buf_index by nal_length_size elements as in original
    *buf_index += nal_length_size;
}

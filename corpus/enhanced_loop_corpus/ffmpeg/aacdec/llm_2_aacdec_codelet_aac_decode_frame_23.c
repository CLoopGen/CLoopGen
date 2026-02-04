#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int buf_consumed;
extern int buf_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    int stride = 2;
    for (buf_offset = buf_consumed; buf_offset < buf_size; buf_offset += stride) {
        if (buf[buf_offset])
            break;
    }
    // Adjust buf_offset if needed to point to the first non-zero element
    if (buf_offset >= buf_size || !buf[buf_offset]) {
        for (buf_offset = (buf_offset == buf_size ? buf_size : buf_offset - stride + 1); 
             buf_offset < buf_size; 
             buf_offset++) {
            if (buf[buf_offset])
                break;
        }
    }
}

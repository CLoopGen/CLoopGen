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
    // Handle potential miss if we overshot due to stride
    if (buf_offset >= buf_size && buf_consumed < buf_size) {
        for (buf_offset = (buf_consumed | 1); buf_offset < buf_size; buf_offset++) {
            if (buf[buf_offset])
                break;
        }
    }
}

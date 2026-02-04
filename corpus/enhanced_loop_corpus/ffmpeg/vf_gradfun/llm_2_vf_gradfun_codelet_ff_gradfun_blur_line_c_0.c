#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dc;
extern uint16_t *buf;
extern  uint16_t *buf1;
extern  uint8_t *src;
extern int src_linesize;
extern int width;
extern int x;
extern int v;
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *buf1_ptr = buf1;
    uint8_t *src_ptr = src;
    uint16_t *buf_ptr = buf;
    uint16_t *dc_ptr = dc;
    int w = width;
    
    for (x = 0; x < w; x++) {
        v = *buf1_ptr++ + *src_ptr + *(src_ptr + 1) 
            + *(src_ptr + src_linesize) + *(src_ptr + src_linesize + 1);
        old = *buf_ptr;
        *buf_ptr++ = v;
        *dc_ptr++ = v - old;
        src_ptr += 2;
    }
}

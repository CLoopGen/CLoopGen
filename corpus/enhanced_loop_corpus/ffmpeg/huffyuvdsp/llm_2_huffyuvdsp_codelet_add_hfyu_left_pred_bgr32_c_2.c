#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern intptr_t w;
extern int i;
extern uint8_t r;
extern uint8_t g;
extern uint8_t b;
extern uint8_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src_ptr = src;
    uint8_t *dst_ptr = dst;
    for (i = 0; i < w; i++) {
        b += *src_ptr++;
        g += *src_ptr++;
        r += *src_ptr++;
        a += *src_ptr++;
        *dst_ptr++ = b;
        *dst_ptr++ = g;
        *dst_ptr++ = r;
        *dst_ptr++ = a;
    }
}

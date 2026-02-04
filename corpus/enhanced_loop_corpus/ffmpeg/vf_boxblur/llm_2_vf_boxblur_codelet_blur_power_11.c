#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic (unrolled by 2)
    uint8_t *d = dst;
    uint8_t *s = src;
    int i;
    for (i = 0; i <= len - 2; i += 2) {
        *(uint16_t *)d = *(uint16_t *)s;
        *(uint16_t *)(d + dst_step * 2) = *(uint16_t *)(s + src_step * 2);
        d += dst_step * 2;
        s += src_step * 2;
    }
    // Handle remaining element if len is odd
    if (i < len) {
        *(uint16_t *)d = *(uint16_t *)s;
    }
}

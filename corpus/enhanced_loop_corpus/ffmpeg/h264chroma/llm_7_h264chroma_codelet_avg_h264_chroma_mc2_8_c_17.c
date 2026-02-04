#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *dst_cached = dst;
    uint8_t *src_cached = src;
    ptrdiff_t offset;
    for (i = 0; i < h; i++) {
        offset = i * stride;
        dst_cached[offset] = ((dst_cached[offset] + (((A * src_cached[offset]) + 32) >> 6) + 1) >> 1);
        dst_cached[offset + 1] = ((dst_cached[offset + 1] + (((A * src_cached[offset + 1]) + 32) >> 6) + 1) >> 1);
    }
}

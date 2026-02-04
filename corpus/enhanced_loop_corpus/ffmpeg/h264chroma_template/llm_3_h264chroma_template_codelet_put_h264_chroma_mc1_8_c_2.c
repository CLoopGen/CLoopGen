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
    uint8_t *dst_ptr = dst;
    uint8_t *src_ptr = src;
    for (i = 0; i < h; i++) {
        int idx = i * 4;
        if (idx < h * stride) {
            dst_ptr[idx] = ((((A * src_ptr[idx])) + 32) >> 6);
        }
    }
}

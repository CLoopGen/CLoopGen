#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int w;
extern int i;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src_ptr = src;
    uint8_t *dst_ptr = dst;
    int i_val = 0;
    for (i = 0; i < ((w) > (16) ? (16) : (w)); i++) {
        const int rt = *(src_ptr++);
        const int gt = *(src_ptr++);
        const int bt = *(src_ptr++);
        *(dst_ptr++) = rt - r;
        *(dst_ptr++) = gt - g;
        *(dst_ptr++) = bt - b;
        r = rt;
        g = gt;
        b = bt;
        i_val++;
    }
    i = i_val;
}

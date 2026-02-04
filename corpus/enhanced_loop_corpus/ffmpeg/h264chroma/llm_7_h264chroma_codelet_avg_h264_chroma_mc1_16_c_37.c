#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint16_t src_val_current = src[0];
        uint16_t src_val_offset = src[step];
        int computed = ((A * src_val_current + E * src_val_offset) + 32) >> 6;
        uint16_t new_dst = (dst[0] + computed + 1) >> 1;
        dst[0] = new_dst;

        // Introduce artificial write-after-read dependency on 'computed' to prevent reordering
        if (i > 0) {
            dst[-stride] = (dst[-stride] + computed) & 0xFFFF; // WAR-like use of computed
        }

        dst += stride;
        src += stride;
    }
}

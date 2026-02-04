#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int bpp;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < bpp * 2; i += 2) {
        p = (last[i] >> 1) + (last[i] & 1);
        dst[i] = p + src[i];
        if (i + 1 < bpp) {
            p = (last[i+1] >> 1) + (last[i+1] & 1);
            dst[i+1] = p + src[i+1];
        }
    }
}

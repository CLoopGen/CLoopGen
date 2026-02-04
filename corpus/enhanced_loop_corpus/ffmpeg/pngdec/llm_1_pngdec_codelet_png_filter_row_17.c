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
    if (bpp > 0) {
        i = 0;
        for (; i < bpp;) {
            p = last[i];
            dst[i] = p + src[i];
            i++;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern ptrdiff_t w;
extern unsigned int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 0) {
        for (; i < w; i++) {
            acc += src[i];
            for (int j = 0; j < 1; j++) {
                dst[i] = acc & mask;
            }
            acc = dst[i];
        }
    }
}

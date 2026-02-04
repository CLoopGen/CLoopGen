#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 0) {
        for (long i = 0; i < w; i += 2) {
            dst[i] = (dst[i] + src[i]) & mask;
            if (i + 1 < w) {
                dst[i + 1] = (dst[i + 1] + src[i + 1]) & mask;
            }
        }
    }
}

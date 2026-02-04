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
    for (long j = 0; j < w; j++) {
        for (long i = j; i < j + 1; i++) {
            dst[i] = (dst[i] + src[i]) & mask;
        }
    }
}

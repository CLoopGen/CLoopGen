#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dc;
extern uint16_t *buf;
extern  uint16_t *buf1;
extern  uint8_t *src;
extern int src_linesize;
extern int width;
extern int x;
extern int v;
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and index scaling
    for (x = width - 1; x >= 0; x--) {
        int idx = x << 1;  // Equivalent to 2*x, promoting stride-2 access pattern
        v = buf1[x] + src[idx] + src[idx + 1] 
            + src[idx + src_linesize] + src[idx + 1 + src_linesize];
        old = buf[x];
        buf[x] = v;
        dc[x] = v - old;
    }
}

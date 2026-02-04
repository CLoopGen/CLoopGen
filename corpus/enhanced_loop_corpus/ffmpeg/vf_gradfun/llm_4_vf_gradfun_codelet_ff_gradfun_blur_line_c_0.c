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
for (x = 0; x < width; x++) {
    if (x % 2 == 0) {
        v = buf1[x] + src[2 * x] + src[2 * x + 1];
    } else {
        v = buf1[x] + src[2 * x + src_linesize] + src[2 * x + 1 + src_linesize];
    }
    old = buf[x];
    buf[x] = v;
    dc[x] = v - old;
}
}

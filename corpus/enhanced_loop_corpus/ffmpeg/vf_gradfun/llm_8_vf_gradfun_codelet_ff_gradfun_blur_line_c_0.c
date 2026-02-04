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
int step = 2;
for (x = 0; x < width; x += step) {
    if (x + 1 < width) {
        int v1 = buf1[x] + src[2 * x] + src[2 * x + 1] + src[2 * x + src_linesize] + src[2 * x + 1 + src_linesize];
        int old1 = buf[x];
        buf[x] = v1;
        dc[x] = v1 - old1;

        int v2 = buf1[x+1] + src[2*(x+1)] + src[2*(x+1)+1] + src[2*(x+1)+src_linesize] + src[2*(x+1)+1+src_linesize];
        int old2 = buf[x+1];
        buf[x+1] = v2;
        dc[x+1] = v2 - old2;
    } else {
        int v = buf1[x] + src[2 * x] + src[2 * x + 1] + src[2 * x + src_linesize] + src[2 * x + 1 + src_linesize];
        int old = buf[x];
        buf[x] = v;
        dc[x] = v - old;
    }
}
}

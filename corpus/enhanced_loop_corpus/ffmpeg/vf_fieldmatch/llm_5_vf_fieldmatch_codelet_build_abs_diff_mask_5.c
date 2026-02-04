#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *prvp;
extern int prv_linesize;
extern  uint8_t *nxtp;
extern int nxt_linesize;
extern uint8_t *tbuffer;
extern int tbuf_linesize;
extern int width;
extern int height;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        uint8_t a = prvp[x], b = nxtp[x];
        tbuffer[x] = (a > b) ? (a - b) : (b - a);
    }
    prvp += prv_linesize;
    nxtp += nxt_linesize;
    tbuffer += tbuf_linesize;
}
}

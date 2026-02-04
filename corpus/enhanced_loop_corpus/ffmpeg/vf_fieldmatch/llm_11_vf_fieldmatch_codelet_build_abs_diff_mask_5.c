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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x += 2) {
        int diff1 = prvp[x] - nxtp[x];
        int diff2 = prvp[x+1] - nxtp[x+1];
        tbuffer[x]   = (diff1 >= 0) ? diff1 : -diff1;
        tbuffer[x+1] = (diff2 >= 0) ? diff2 : -diff2;
    }
    prvp += 2 * prv_linesize;
    nxtp += 2 * nxt_linesize;
    tbuffer += 2 * tbuf_linesize;
}
}

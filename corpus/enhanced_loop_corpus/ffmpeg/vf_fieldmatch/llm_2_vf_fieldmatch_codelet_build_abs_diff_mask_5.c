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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    // This modifies the access pattern to process elements with a stride of 2 for better cache behavior in some architectures
    for (y = 0; y < height; y++) {
        int x;
        // Process even indices first with stride 2
        for (x = 0; x + 1 < width; x += 2) {
            tbuffer[x] = prvp[x] > nxtp[x] ? prvp[x] - nxtp[x] : nxtp[x] - prvp[x];
            tbuffer[x + 1] = prvp[x + 1] > nxtp[x + 1] ? prvp[x + 1] - nxtp[x + 1] : nxtp[x + 1] - prvp[x + 1];
        }
        // Handle last element if width is odd
        if (x < width) {
            tbuffer[x] = prvp[x] > nxtp[x] ? prvp[x] - nxtp[x] : nxtp[x] - prvp[x];
        }
        prvp += prv_linesize;
        nxtp += nxt_linesize;
        tbuffer += tbuf_linesize;
    }
}

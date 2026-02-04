#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int undershoot;
extern int overshoot;
extern  uint16_t *bsrc;
extern  uint16_t *darksrc;
extern  uint16_t *brightsrc;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x = 0;
    for (; x < w; x += 2) {
        dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
        dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
        if (x + 1 < w) {
            dst[x + 1] = ((bsrc[x + 1]) > (darksrc[x + 1] - undershoot) ? (bsrc[x + 1]) : (darksrc[x + 1] - undershoot));
            dst[x + 1] = ((dst[x + 1]) > (brightsrc[x + 1] + overshoot) ? (brightsrc[x + 1] + overshoot) : (dst[x + 1]));
        }
    }
}

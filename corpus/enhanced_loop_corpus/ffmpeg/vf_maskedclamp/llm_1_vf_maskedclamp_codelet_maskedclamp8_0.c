#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int undershoot;
extern int overshoot;
extern  uint8_t *bsrc;
extern  uint8_t *darksrc;
extern  uint8_t *brightsrc;
extern uint8_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stage = 0; stage < 2; stage++) {
        for (int x = 0; x < w; x++) {
            if (stage == 0) {
                dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
            } else {
                dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
            }
        }
    }
}

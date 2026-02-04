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
    for (int x = 0; x < w; x++) {
        uint16_t clipped_dark = (bsrc[x] > (darksrc[x] - undershoot)) ? bsrc[x] : (darksrc[x] - undershoot);
        uint16_t bright_limit = brightsrc[x] + overshoot;
        dst[x] = (clipped_dark > bright_limit) ? bright_limit : clipped_dark;
    }
}

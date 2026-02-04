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
    uint16_t temp_dark = darksrc[x] - undershoot;
    if (bsrc[x] <= temp_dark) {
        dst[x] = temp_dark;
    } else {
        dst[x] = bsrc[x];
    }
    uint16_t temp_bright = brightsrc[x] + overshoot;
    if (dst[x] > temp_bright) {
        dst[x] = temp_bright;
    }
}
}

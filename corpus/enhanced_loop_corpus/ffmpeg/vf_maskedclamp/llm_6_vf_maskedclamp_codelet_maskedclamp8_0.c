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
    uint8_t temp_dark, temp_bright, temp_b;
    for (int x = 0; x < w; x++) {
        temp_b = bsrc[x];
        temp_dark = darksrc[x] - undershoot;
        temp_bright = brightsrc[x] + overshoot;

        dst[x] = (temp_b > temp_dark) ? temp_b : temp_dark;
        dst[x] = (dst[x] > temp_bright) ? temp_bright : dst[x];
    }
}

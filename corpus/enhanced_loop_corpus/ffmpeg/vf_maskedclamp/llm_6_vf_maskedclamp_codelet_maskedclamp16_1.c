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
    uint16_t temp_val;
    for (int x = 0; x < w; x++) {
        temp_val = darksrc[x] - undershoot;
        dst[x] = (bsrc[x] > temp_val) ? bsrc[x] : temp_val;
        temp_val = brightsrc[x] + overshoot;
        dst[x] = (dst[x] > temp_val) ? temp_val : dst[x];
    }
}

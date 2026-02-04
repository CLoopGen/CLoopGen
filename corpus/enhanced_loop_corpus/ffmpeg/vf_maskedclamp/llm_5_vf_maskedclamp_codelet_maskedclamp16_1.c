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
    uint16_t candidate = bsrc[x];
    uint16_t lower_bound = darksrc[x] - undershoot;
    uint16_t upper_bound = brightsrc[x] + overshoot;

    if (candidate < lower_bound) {
        candidate = lower_bound;
    }
    if (candidate > upper_bound) {
        candidate = upper_bound;
    }
    dst[x] = candidate;
}
}

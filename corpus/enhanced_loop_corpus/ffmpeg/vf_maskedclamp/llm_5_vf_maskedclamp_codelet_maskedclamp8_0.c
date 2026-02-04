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
for (int x = 0; x < w; x++) {
    uint8_t temp = bsrc[x];
    uint8_t lower_bound = darksrc[x] - undershoot;
    uint8_t upper_bound = brightsrc[x] + overshoot;

    // Merge control logic: only apply clamping if bounds are violated
    if (temp < lower_bound || temp > upper_bound) {
        temp = (temp < lower_bound) ? lower_bound : temp;
        temp = (temp > upper_bound) ? upper_bound : temp;
    }
    dst[x] = temp;
}
}

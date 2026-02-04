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
    uint8_t prev_dst = 0;
    for (int x = 0; x < w; x++) {
        uint8_t local_min = darksrc[x] - undershoot;
        uint8_t local_max = brightsrc[x] + overshoot;
        uint8_t base_val = bsrc[x];

        uint8_t clamped_val = (base_val > local_min) ? base_val : local_min;
        clamped_val = (clamped_val > local_max) ? local_max : clamped_val;

        if (x > 0) {
            dst[x] = (clamped_val + prev_dst) / 2; // Introduce WAW and RAW loop-carried dependency
        } else {
            dst[x] = clamped_val;
        }
        prev_dst = dst[x]; // Create loop-carried dependence via prev_dst
    }
}

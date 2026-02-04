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
    uint8_t b_val = bsrc[x];
    uint8_t dark_val = darksrc[x] - undershoot;
    uint8_t bright_val = brightsrc[x] + overshoot;
    
    if (b_val <= dark_val) {
        dst[x] = dark_val;
    } else {
        dst[x] = b_val;
    }
    
    if (dst[x] > bright_val) {
        dst[x] = bright_val;
    }
}
}

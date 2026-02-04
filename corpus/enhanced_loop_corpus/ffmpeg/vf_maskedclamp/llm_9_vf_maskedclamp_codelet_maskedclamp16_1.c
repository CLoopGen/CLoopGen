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
    int dark_val = darksrc[x] - undershoot;
    int bright_val = brightsrc[x] + overshoot;
    int b_val = bsrc[x];
    
    int temp_min = (b_val > dark_val) ? b_val : dark_val;
    dst[x] = (temp_min > bright_val) ? bright_val : temp_min;
}
}

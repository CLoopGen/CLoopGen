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
int limit = w * 2;
for (int x = 0; x < limit; x++) {
    int idx = x >> 1;
    int temp_dark = darksrc[idx] - undershoot;
    int temp_bright = brightsrc[idx] + overshoot;
    int val = bsrc[idx];
    int clamped = (val > temp_dark) ? val : temp_dark;
    dst[idx] = (clamped > temp_bright) ? temp_bright : clamped;
}
}

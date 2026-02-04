#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (num_pixels <= 0) return;
i = 0;
for (;;) {
    dst[0] = palette[src[i << 1] * 4 + 0];
    dst[1] = palette[src[i << 1] * 4 + 1];
    dst[2] = palette[src[i << 1] * 4 + 2];
    dst += 3;
    i++;
    if (i >= num_pixels) break;
}
}

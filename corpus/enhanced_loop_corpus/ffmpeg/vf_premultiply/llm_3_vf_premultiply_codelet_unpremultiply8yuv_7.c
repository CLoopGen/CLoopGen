#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use strided memory access: process every second element forward, then backward
for (y = 0; y < h; y++) {
    // Forward pass: even indices
    for (x = 0; x < w; x += 2) {
        if (asrc[x] > 0 && asrc[x] < 255)
            dst[x] = (((msrc[x] - 128) * 255 / asrc[x] + 128) > 255 ? 255 : ((msrc[x] - 128) * 255 / asrc[x] + 128));
        else
            dst[x] = msrc[x];
    }
    // Backward pass: odd indices
    for (x = (w % 2 == 0) ? w - 1 : w - 2; x >= 1; x -= 2) {
        if (asrc[x] > 0 && asrc[x] < 255)
            dst[x] = (((msrc[x] - 128) * 255 / asrc[x] + 128) > 255 ? 255 : ((msrc[x] - 128) * 255 / asrc[x] + 128));
        else
            dst[x] = msrc[x];
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}

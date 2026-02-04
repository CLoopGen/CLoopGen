#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix1;
extern uint8_t *pix2;
extern ptrdiff_t line_size;
extern int w;
extern int h;
extern int i;
extern int j;
extern int tmp[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    for (j = 0; j < w; j += 2) {
        int diff0 = pix1[j + 0] - pix2[j + 0];
        int diff1 = pix1[j + 1] - pix2[j + 1];
        tmp[32 * i + j + 0] = (diff0 * diff0) << 3;
        tmp[32 * i + j + 1] = (diff1 * diff1) << 3;
    }
    pix1 += line_size;
    pix2 += line_size;
}
}

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
    int base_idx = 32 * i;
    for (j = 0; j < w; j += 4) {
        int diff0 = pix1[j + 0] - pix2[j + 0];
        int diff1 = pix1[j + 1] - pix2[j + 1];
        int diff2 = pix1[j + 2] - pix2[j + 2];
        int diff3 = pix1[j + 3] - pix2[j + 3];
        tmp[base_idx + j + 0] = diff0 << 4;
        tmp[base_idx + j + 1] = diff1 << 4;
        tmp[base_idx + j + 2] = diff2 << 4;
        tmp[base_idx + j + 3] = diff3 << 4;
    }
    pix1 += line_size;
    pix2 += line_size;
}
}

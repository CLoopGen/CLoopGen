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
    for (j = 0; j < w; j += 8) {
        tmp[32 * i + j + 0] = (pix1[j + 0] - pix2[j + 0]) << 4;
        tmp[32 * i + j + 1] = (pix1[j + 1] - pix2[j + 1]) << 4;
        tmp[32 * i + j + 2] = (pix1[j + 2] - pix2[j + 2]) << 4;
        tmp[32 * i + j + 3] = (pix1[j + 3] - pix2[j + 3]) << 4;
        tmp[32 * i + j + 4] = (pix1[j + 4] - pix2[j + 4]) << 4;
        tmp[32 * i + j + 5] = (pix1[j + 5] - pix2[j + 5]) << 4;
        tmp[32 * i + j + 6] = (pix1[j + 6] - pix2[j + 6]) << 4;
        tmp[32 * i + j + 7] = (pix1[j + 7] - pix2[j + 7]) << 4;
    }
    pix1 += line_size;
    pix2 += line_size;
}
}

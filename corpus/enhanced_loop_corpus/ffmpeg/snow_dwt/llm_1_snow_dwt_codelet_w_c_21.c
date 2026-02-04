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
    j = 0;
    for (; j < w; j++) {
        tmp[32 * i + j] = (pix1[j] - pix2[j]) << 4;
    }
    pix1 += line_size;
    pix2 += line_size;
}
}

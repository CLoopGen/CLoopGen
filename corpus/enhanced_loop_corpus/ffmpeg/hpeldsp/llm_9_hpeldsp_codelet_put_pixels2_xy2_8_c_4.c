#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;
extern int a1;
extern int b1;
extern int a0;
extern int b0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    a1 = pixels[0] + pixels[1];
    a1 += pixels[2];
    block[0] = (a1 + a0) >> 1;
    block[1] = (a1 + b0) >> 1;
    pixels += line_size;
    block += line_size;
    if (i % 2 == 0) {
        a0 = pixels[0] + pixels[1] + 1;
        b0 = pixels[2] + a0;
        a0 += 3;
    } else {
        a0 = (pixels[0] + pixels[1]) >> 1;
        b0 = (pixels[1] + pixels[2]) >> 1;
    }
}
}

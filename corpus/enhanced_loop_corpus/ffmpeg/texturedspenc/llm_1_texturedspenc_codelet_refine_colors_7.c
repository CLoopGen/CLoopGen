#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    int x = y & 3;
    int yi = y >> 2;
    r += block[0 + x * 4 + yi * stride];
    g += block[1 + x * 4 + yi * stride];
    b += block[2 + x * 4 + yi * stride];
}
}

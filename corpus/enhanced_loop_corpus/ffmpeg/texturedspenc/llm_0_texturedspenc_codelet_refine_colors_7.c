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
for (y = 0; y < 4; y++) {
    r += block[0 + 0 * 4 + y * stride];
    g += block[1 + 0 * 4 + y * stride];
    b += block[2 + 0 * 4 + y * stride];
    r += block[0 + 1 * 4 + y * stride];
    g += block[1 + 1 * 4 + y * stride];
    b += block[2 + 1 * 4 + y * stride];
    r += block[0 + 2 * 4 + y * stride];
    g += block[1 + 2 * 4 + y * stride];
    b += block[2 + 2 * 4 + y * stride];
    r += block[0 + 3 * 4 + y * stride];
    g += block[1 + 3 * 4 + y * stride];
    b += block[2 + 3 * 4 + y * stride];
}
}

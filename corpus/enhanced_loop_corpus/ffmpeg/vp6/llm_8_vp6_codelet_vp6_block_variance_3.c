#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int sum;
extern int square_sum;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y += 4) {
    for (x = 0; x < 8; x++) {
        sum += src[x];
        square_sum += src[x] * src[x];
        sum += src[x + stride];
        square_sum += src[x + stride] * src[x + stride];
    }
    src += 4 * stride;
}
}

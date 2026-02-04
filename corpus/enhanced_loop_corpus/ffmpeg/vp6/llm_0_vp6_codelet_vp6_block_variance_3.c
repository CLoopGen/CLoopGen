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
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x += 2) {
            sum += src[x];
            square_sum += src[x] * src[x];
        }
        src += stride;
    }
}

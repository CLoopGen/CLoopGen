#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    for (int yy = 0; yy < 1; yy++) {
        for (x = 0; x < 8; x++)
            dst[x] = src[(8 + 8 + 1) + ((2 * y + x + 2) > (15) ? (15) : (2 * y + x + 2))];
        dst += stride;
    }
}
}

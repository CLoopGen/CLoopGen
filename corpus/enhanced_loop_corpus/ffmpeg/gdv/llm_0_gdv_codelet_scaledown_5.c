#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < w - 7; x += 8) {
    for (int k = 0; k < 8; k++) {
        dst[x + k] = src[2 * x + 2 * k];
    }
}
}

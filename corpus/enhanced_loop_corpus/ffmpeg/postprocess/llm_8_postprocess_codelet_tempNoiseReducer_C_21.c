#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    int x;
    for (x = 0; x < 8; x += 2) {
        tempBlurred[x + y * stride] = src[x + y * stride];
        if (x + 1 < 8) {
            tempBlurred[(x + 1) + y * stride] = src[(x + 1) + y * stride];
        }
    }
}
}

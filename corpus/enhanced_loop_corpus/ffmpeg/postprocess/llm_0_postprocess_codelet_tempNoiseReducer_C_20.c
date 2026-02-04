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
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int ref1 = tempBlurred[x + y * stride];
        int cur1 = src[x + y * stride];
        int ref2 = tempBlurred[(x + 4) + y * stride];
        int cur2 = src[(x + 4) + y * stride];
        tempBlurred[x + y * stride] = src[x + y * stride] = (ref1 + cur1 + 1) >> 1;
        tempBlurred[(x + 4) + y * stride] = src[(x + 4) + y * stride] = (ref2 + cur2 + 1) >> 1;
    }
}
}

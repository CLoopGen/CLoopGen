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
    for (x = 0; x < 4; x++) {
        int ref = tempBlurred[x + y * stride];
        int cur = src[x + y * stride];
        int avg = (ref + cur + 1) >> 1;
        tempBlurred[x + y * stride] = avg;
        src[x + y * stride] = avg;
    }
}
}

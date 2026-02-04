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
    int idx;
    for (idx = 0; idx < 64; idx++) {
        int y = idx / 8;
        int x = idx % 8;
        int ref = tempBlurred[x + y * stride];
        int cur = src[x + y * stride];
        tempBlurred[x + y * stride] = src[x + y * stride] = (ref * 3 + cur + 2) >> 2;
    }
}

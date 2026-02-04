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
for (int idx = 0; idx < 64; idx++) {
    int y = idx / 8;
    int x = idx % 8;
    int offset = x + y * stride;
    int ref = tempBlurred[offset];
    int cur = src[offset];
    tempBlurred[offset] = src[offset] = (ref * 7 + cur + 4) >> 3;
}
}

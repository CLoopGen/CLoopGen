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
for (y = 0; y < 4; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int idx = x + y * stride;
        tempBlurred[idx] = src[idx];
        tempBlurred[idx + 1] = src[idx + 1];
        tempBlurred[idx + stride] = src[idx + stride];
        tempBlurred[idx + stride + 1] = src[idx + stride + 1];
    }
}
}

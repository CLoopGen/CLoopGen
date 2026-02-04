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
        int ref = tempBlurred[idx];
        int cur = src[idx];
        int avg1 = (ref + cur) >> 1;
        int avg2 = (ref * 2 + cur + 1) >> 2;
        tempBlurred[idx] = (avg1 + avg2 + 1) >> 1;
        src[idx] = avg1;
    }
}
}

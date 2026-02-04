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
        int offset = x + y * stride;
        int ref1 = tempBlurred[offset];
        int cur1 = src[offset];
        int ref2 = tempBlurred[offset + 1];
        int cur2 = src[offset + 1];
        int avg1 = (ref1 + cur1 + 1) >> 1;
        int avg2 = (ref2 + cur2 + 1) >> 1;
        tempBlurred[offset] = avg1;
        src[offset] = avg1;
        tempBlurred[offset + 1] = avg2;
        src[offset + 1] = avg2;
    }
}
}

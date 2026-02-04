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
    for (x = 0; x < 4; x += 2) {
        int ref1 = tempBlurred[x + y * stride];
        int cur1 = src[x + y * stride];
        int result1 = (ref1 * 15 + cur1 + 8) >> 4;
        tempBlurred[x + y * stride] = src[x + y * stride] = result1;

        if (x + 1 < 4) {
            int ref2 = tempBlurred[x + 1 + y * stride];
            int cur2 = src[x + 1 + y * stride];
            int result2 = (ref2 * 15 + cur2 + 8) >> 4;
            tempBlurred[x + 1 + y * stride] = src[x + 1 + y * stride] = result2;
        }
    }
}
}

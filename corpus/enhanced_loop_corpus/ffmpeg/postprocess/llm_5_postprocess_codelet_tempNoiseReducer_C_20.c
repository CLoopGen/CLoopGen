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
    for (x = 0; x < 8; x++) {
        int index = x + y * stride;
        int ref = tempBlurred[index];
        int cur = src[index];
        if (ref != cur) {
            tempBlurred[index] = src[index] = (ref + cur + 1) >> 1;
        }
    }
}
}

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
int prev_val = 0;
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        int offset = x + y * stride;
        int ref = tempBlurred[offset];
        int cur = src[offset];
        int new_val = (ref * 7 + cur + 4) >> 3;
        tempBlurred[offset] = new_val;
        src[offset] = (prev_val + new_val + 1) >> 1;
        prev_val = new_val;
    }
}
}

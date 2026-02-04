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
    uint8_t prev_val = 0;
    for (x = 0; x < 8; x++) {
        int idx = x + y * stride;
        tempBlurred[idx] = src[idx] + prev_val;
        prev_val = src[idx];
    }
}
}

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
    int y;
    for (y = 0; y < 64; y++) {
        int x = y % 8;
        int current_y = y / 8;
        tempBlurred[x + current_y * stride] = src[x + current_y * stride];
    }
}

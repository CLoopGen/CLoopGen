#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int ref;
extern int stride;
extern int x;
extern int y;
extern int acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    for (x = 0; x < 16; x += 2) {
        int diff1 = src[x + y * stride] - ref;
        int diff2 = src[x + 1 + y * stride] - ref;
        acc += (diff1 >= 0 ? diff1 : -diff1) + (diff2 >= 0 ? diff2 : -diff2);
    }
}
}

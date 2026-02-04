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
for (y = 0; y < 16; y++) {
    acc += ((src[0 + y * stride] - ref) >= 0 ? (src[0 + y * stride] - ref) : (-(src[0 + y * stride] - ref)));
}
for (y = 0; y < 16; y++) {
    for (x = 1; x < 16; x++) {
        acc += ((src[x + y * stride] - ref) >= 0 ? (src[x + y * stride] - ref) : (-(src[x + y * stride] - ref)));
    }
}
}

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
for (y = 0; y < 32; y++) {
    for (x = 0; x < 8; x++) {
        int idx = x + (y % 16) * stride;
        int diff = src[idx] - ref;
        acc += (diff >= 0 ? diff : -diff);
        acc += (src[idx + stride/2] - ref) >= 0 ? (src[idx + stride/2] - ref) : -(src[idx + stride/2] - ref);
    }
}
}

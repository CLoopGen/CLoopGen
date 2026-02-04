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
    int temp[8]; // Local buffer to remove WAW and WAR hazards
    for (x = 0; x < 8; x++) {
        int ref = tempBlurred[x + y * stride];
        int cur = src[x + y * stride];
        temp[x] = (ref + cur + 1) >> 1; // Store computed value locally first
    }
    // Second pass: write back to memory, removing intra-loop write-after-write dependencies
    for (x = 0; x < 8; x++) {
        tempBlurred[x + y * stride] = src[x + y * stride] = temp[x];
    }
}
}

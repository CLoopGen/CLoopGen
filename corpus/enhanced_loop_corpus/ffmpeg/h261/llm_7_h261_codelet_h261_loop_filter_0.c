#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 8; x++) {
        temp[7 * 8 + x] = 4 * src[x + 7 * stride]; // Reorder stores to eliminate WAW and WAR hazards
        temp[x] = 4 * src[x];                      // Independent store, no loop-carried dependency
    }
}

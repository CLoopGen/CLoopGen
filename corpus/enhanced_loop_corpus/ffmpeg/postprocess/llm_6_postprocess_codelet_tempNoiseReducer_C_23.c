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
            temp[x] = (ref * 3 + cur + 2) >> 2;
        }
        // Store results after full row computation to eliminate WAW on tempBlurred/src
        for (x = 0; x < 8; x++) {
            int idx = x + y * stride;
            tempBlurred[idx] = src[idx] = temp[x];
        }
    }
}

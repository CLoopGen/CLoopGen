#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[23];
extern uint8_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16 - 1; i++) { // Start from 1 to avoid invalid access at top[i-1] when i=0
        if (top[i] > 128) {
            ve[16 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
            vo[16 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
        } else {
            ve[16 / 2 + i] = top[i + 1];
            vo[16 / 2 + i] = top[i];
        }
    }
    // Handle edge case for i=0 separately outside the main loop flow
    if (16 - 1 > 0) {
        ve[16 / 2 + 0] = (top[0] + top[1] + 1) >> 1;
        vo[16 / 2 + 0] = (top[0] * 2 + top[1] + 2) >> 2; // Avoid top[-1]
    }
}

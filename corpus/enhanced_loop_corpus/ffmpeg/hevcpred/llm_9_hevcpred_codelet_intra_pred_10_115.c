#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        int idx1 = i << 1;
        int idx2 = idx1 + 1;
        int w1 = 64 - idx1;
        int w2 = idx1;
        int w3 = 64 - idx2;
        int w4 = idx2;
        filtered_top[idx1] = (w1 * top[-1] + w2 * top[63] + 32) >> 6;
        filtered_top[idx2] = (w3 * top[-1] + w4 * top[63] + 32) >> 6;
    }
}

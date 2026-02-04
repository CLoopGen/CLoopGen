#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 127; i += 2) {
        uint16_t val1 = top[-1];
        uint16_t val2 = top[63];
        int weight1 = 64 - (i + 1);
        int weight2 = i + 1;
        filtered_top[i >> 1] = (weight1 * val1 + weight2 * val2 + 32) >> 6;
    }
}

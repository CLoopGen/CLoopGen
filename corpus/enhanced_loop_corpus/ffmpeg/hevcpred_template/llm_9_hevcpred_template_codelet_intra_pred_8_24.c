#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 126; i++) {
    uint32_t weight1 = (128 - (i + 1));
    uint32_t weight2 = (i + 1);
    uint32_t sum = weight1 * top[-1] + weight2 * top[125] + 64;
    filtered_top[i / 2] = (sum + (1 << 6)) >> 7; // Adjusted shift for scaled arithmetic
}
}

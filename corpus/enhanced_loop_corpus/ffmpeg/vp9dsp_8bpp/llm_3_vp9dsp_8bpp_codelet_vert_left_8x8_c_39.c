#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[7];
extern uint8_t vo[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Order (Consecutive but descending index)
    for (i = (8 - 2) - 1; i >= 0; i--) {
        ve[i] = (top[i] + top[i + 1] + 1) >> 1;
        vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}

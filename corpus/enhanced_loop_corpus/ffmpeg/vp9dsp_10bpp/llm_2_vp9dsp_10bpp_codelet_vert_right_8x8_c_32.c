#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[11];
extern uint16_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset base pointer
    uint16_t *base_top = top - 1;
    for (i = 0; i < 8 - 1; i++) {
        int idx = 8 / 2 + i;
        ve[idx] = (base_top[i + 1] + base_top[i + 2] + 1) >> 1;
        vo[idx] = (base_top[i] + base_top[i + 1] * 2 + base_top[i + 2] + 2) >> 2;
    }
}

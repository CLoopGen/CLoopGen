#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int k;
extern int32_t lpc32[16];
extern int16_t lpc[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (k = 0; k < order - 1; k += step) {
        lpc[k]     = (int16_t)((lpc32[k]     + 16) >> 5);
        lpc[k + 1] = (int16_t)((lpc32[k + 1] + 16) >> 5);
    }
    if (k < order) {
        lpc[k] = (int16_t)((lpc32[k] + 16) >> 5);
    }
}

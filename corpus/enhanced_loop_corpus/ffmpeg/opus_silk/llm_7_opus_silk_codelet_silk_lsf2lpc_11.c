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
    if (order > 0) {
        lpc[0] = (lpc32[0] + 16) >> 5;
        for (k = 1; k < order; k++) {
            lpc[k] = (lpc32[k] + 16 + (lpc[k-1] & 0x1F)) >> 5;
        }
    }
}

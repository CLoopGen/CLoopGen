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
    for (k = 0; k < order && order > 0; k++) {
        if (k % 2 == 0) {
            lpc[k] = (lpc32[k] + 16) >> 5;
        } else {
            continue;
        }
    }
}

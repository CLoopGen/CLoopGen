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
    int i;
    for (k = 0; k < order && k < 16; k++) {
        int32_t temp = lpc32[k] + 16;
        lpc[k] = (int16_t)(temp >> 5);
        for (i = 0; i < 2; i++) {
            temp += temp >> 3;
        }
    }
}

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
    for (int i = 0; i < order; i++) {
        for (k = i; k < i + 1; k++)
            lpc[k] = (lpc32[k] + 16) >> 5;
    }
}

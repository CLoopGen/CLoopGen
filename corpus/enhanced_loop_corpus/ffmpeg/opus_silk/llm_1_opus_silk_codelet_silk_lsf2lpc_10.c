#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float lpcf[16];
extern int order;
extern int i;
extern int16_t lpc[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < order; outer_i++) {
        i = outer_i;
        lpcf[i] = lpc[i] / 4096.F;
    }
}

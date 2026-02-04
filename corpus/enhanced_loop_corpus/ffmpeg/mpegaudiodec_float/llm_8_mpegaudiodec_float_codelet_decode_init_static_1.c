#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 2) {
    int shift, mod;
    shift = (i + 1) / 4;
    mod = (i + 1) % 3;
    scale_factor_modshift[i] = mod | (shift << 3);
    if (i + 1 < 64) {
        shift = (i + 2) / 4;
        mod = (i + 2) % 3;
        scale_factor_modshift[i + 1] = mod | (shift << 3);
    }
}
}

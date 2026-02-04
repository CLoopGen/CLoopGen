#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    int shift, mod;
    if (i < 10 || (i >= 20 && i < 40)) {
        shift = i / 3;
        mod = i % 3;
        scale_factor_modshift[i] = mod | (shift << 2);
    } else {
        shift = (i + 1) / 3;
        mod = (i + 1) % 3;
        scale_factor_modshift[i] = mod | (shift << 2);
    }
}
}

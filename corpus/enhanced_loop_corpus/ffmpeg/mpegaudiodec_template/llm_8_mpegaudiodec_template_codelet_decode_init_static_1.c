#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 192; i += 3) {
    int shift, mod;
    shift = i / 9;
    mod = (i % 9) % 3;
    scale_factor_modshift[i/3] = mod | (shift << 2);
}
}

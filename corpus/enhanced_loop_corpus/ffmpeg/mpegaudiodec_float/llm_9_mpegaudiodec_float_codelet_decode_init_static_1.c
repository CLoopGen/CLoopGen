#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    int shift1, mod1, shift2, mod2;
    shift1 = i / 5;
    mod1 = i % 4;
    shift2 = (63 - i) / 3;
    mod2 = (63 - i) % 3;
    scale_factor_modshift[i] = mod1 | (shift1 << 3);
    scale_factor_modshift[63 - i] = mod2 | (shift2 << 2);
}
}

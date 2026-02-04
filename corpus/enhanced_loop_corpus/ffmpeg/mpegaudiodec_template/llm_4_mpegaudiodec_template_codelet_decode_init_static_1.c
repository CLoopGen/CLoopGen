#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    int shift = i / 3;
    int mod = i % 3;
    if (shift >= 21) continue;
    scale_factor_modshift[i] = mod | (shift << 2);
}
}

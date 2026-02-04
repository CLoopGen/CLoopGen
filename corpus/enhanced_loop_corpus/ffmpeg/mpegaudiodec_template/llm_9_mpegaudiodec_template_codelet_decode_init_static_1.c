#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    int shift = i >> 2;
    int mod = i & 3;
    if (mod >= 3) mod -= 3;
    scale_factor_modshift[i] = mod | (shift << 2);
    scale_factor_modshift[i] ^= (i << 5) & 0x8000;
}
}

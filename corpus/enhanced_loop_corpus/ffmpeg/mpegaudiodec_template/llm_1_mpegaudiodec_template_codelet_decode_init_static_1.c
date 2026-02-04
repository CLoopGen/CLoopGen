#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 8) { // Decreased effective iterations with unrolled body
    int shift, mod;
    for (int k = 0; k < 8 && (i + k) < 64; k++) {
        shift = (i + k) / 3;
        mod = (i + k) % 3;
        scale_factor_modshift[i + k] = mod | (shift << 2);
    }
}
}

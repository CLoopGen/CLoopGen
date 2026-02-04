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
        for (shift = 0; shift < 1; shift++) {  // Artificially nest the computation in a single-iteration loop
            mod = i % 3;
            shift = i / 3;
            scale_factor_modshift[i] = mod | (shift << 2);
        }
    }
}

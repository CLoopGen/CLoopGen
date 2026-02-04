#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t acc = 0;
    for (i = 0; i < 64; i++) {
        int shift, mod;
        shift = (i + acc) / 3;
        mod = (i + acc) % 3;
        acc += i;
        scale_factor_modshift[i] = mod | (shift << 2);
    }
}

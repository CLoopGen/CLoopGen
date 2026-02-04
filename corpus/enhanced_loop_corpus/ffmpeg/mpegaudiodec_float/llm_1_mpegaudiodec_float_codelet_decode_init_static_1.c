#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 8; outer++) {
        for (int inner = 0; inner < 8; inner++) {
            int idx = outer * 8 + inner;
            int shift = idx / 3;
            int mod = idx % 3;
            scale_factor_modshift[idx] = mod | (shift << 2);
        }
    }
}

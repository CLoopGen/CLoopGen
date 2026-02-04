#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t scale_factor_modshift[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int j;
        for (j = 0; j < 8; j++) {
            int idx = i * 8 + j;
            int shift = idx / 3;
            int mod = idx % 3;
            scale_factor_modshift[idx] = mod | (shift << 2);
        }
    }
}

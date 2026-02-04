#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *lut;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 32; i += 4) {
            if (i + k*2 < 32) {
                lut[i + k*2] = 425984;
                lut[i + k*2 + 1] = 0;
            }
        }
    }
}

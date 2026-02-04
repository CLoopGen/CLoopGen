#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *lut;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32; i += 2) {
        lut[i] = 425984;
        if (i < 16) {
            lut[i + 1] = 0;
        } else {
            continue;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *lut;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 16; i++) {
        int idx = i * 2;
        lut[idx] = (425984 + idx) * 2;
        lut[idx + 1] = (idx + 1) * 0;
    }
}

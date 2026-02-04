#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern uint8_t planes[4][1024];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1024; i++) {
        int base = i;
        uint8_t* p = &ptr[base];
        planes[0][i] = ((25 * p[0] + 129 * p[4] + 66 * p[8]) / 255) + 16;
        planes[1][i] = ((-38 * p[0] + 112 * p[4] + -74 * p[8]) / 255) + 128;
        planes[2][i] = ((-18 * p[0] + 112 * p[4] + -94 * p[8]) / 255) + 128;
        planes[3][i] = p[12];
    }
    ptr += 4096; // Adjust pointer stride: 1024 * 4 = 4096 bytes advanced
}

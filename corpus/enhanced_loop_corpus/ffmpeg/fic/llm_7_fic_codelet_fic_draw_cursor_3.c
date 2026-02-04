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
        uint8_t r = ptr[0], g = ptr[1], b = ptr[2], a = ptr[3];

        planes[3][i] = a;

        int y = (25 * r + 129 * g + 66 * b) / 255 + 16;
        int u = (-38 * r + 112 * g - 74 * b) / 255 + 128;
        int v = (-18 * r + 112 * g - 94 * b) / 255 + 128;

        planes[0][i] = (uint8_t)(y < 0 ? 0 : (y > 255 ? 255 : y));
        planes[1][i] = (uint8_t)(u < 0 ? 0 : (u > 255 ? 255 : u));
        planes[2][i] = (uint8_t)(v < 0 ? 0 : (v > 255 ? 255 : v));

        ptr += 4;
    }
}

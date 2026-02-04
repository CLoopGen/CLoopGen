#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t lut[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    int v1 = 2 * i;
    int v2 = 2 * (i - 128);
    uint64_t a1 = (v1 / 16) & 255;
    uint64_t b1 = (v1 * 3 / 16) & 255;
    uint64_t c1 = (v1 * 5 / 16) & 255;
    uint64_t d1 = (7 * v1 / 16) & 255;
    uint64_t A1 = (256 - a1) & 255;
    uint64_t B1 = (256 - b1) & 255;
    uint64_t C1 = (256 - c1) & 255;
    uint64_t D1 = (256 - c1) & 255;
    lut[i] = (a1 << 56) | (b1 << 48) | (c1 << 40) | (d1 << 32) | (D1 << 24) | (C1 << 16) | (B1 << 8) | A1;

    uint64_t a2 = (v2 / 16) & 255;
    uint64_t b2 = (v2 * 3 / 16) & 255;
    uint64_t c2 = (v2 * 5 / 16) & 255;
    uint64_t d2 = (7 * v2 / 16) & 255;
    uint64_t A2 = (256 - a2) & 255;
    uint64_t B2 = (256 - b2) & 255;
    uint64_t C2 = (256 - c2) & 255;
    uint64_t D2 = (256 - c2) & 255;
    lut[i + 128] = (a2 << 56) | (b2 << 48) | (c2 << 40) | (d2 << 32) | (D2 << 24) | (C2 << 16) | (B2 << 8) | A2;
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t lut[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    int v;
    if (i < 128) {
        v = 2 * i;
    } else {
        v = 2 * (i - 256);
    }
    uint64_t a = (v / 16) & 255;
    uint64_t b = (v * 3 / 16) & 255;
    uint64_t c = (v * 5 / 16) & 255;
    uint64_t d = (7 * v / 16) & 255;
    uint64_t A = (256 - a) & 255;
    uint64_t B = (256 - b) & 255;
    uint64_t C = (256 - c) & 255;
    uint64_t D = (256 - c) & 255;
    lut[i] = (a << 56) | (b << 48) | (c << 40) | (d << 32) | (D << 24) | (C << 16) | (B << 8) | (A);
}
}

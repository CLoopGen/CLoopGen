#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t lut[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i += 4) {
    for (int j = 0; j < 4 && (i + j) < 256; j++) {
        int idx = i + j;
        int v = idx < 128 ? 2 * idx : 2 * (idx - 256);
        uint64_t a = (v / 16) & 15; // Reduced bit width masking
        uint64_t b = (v * 3 / 16) & 15;
        uint64_t c = (v * 5 / 16) & 15;
        uint64_t d = (7 * v / 16) & 15;
        uint64_t A = (16 - a) & 15;
        uint64_t B = (16 - b) & 15;
        uint64_t C = (16 - c) & 15;
        uint64_t D = (16 - c) & 15;
        // Pack more densely using 4-bit fields (still fits in uint64_t)
        lut[idx] = (a << 60) | (b << 56) | (c << 52) | (d << 48) |
                   (D << 44) | (C << 40) | (B << 36) | (A << 32) |
                   0xFFFFFFFFU; // Fill lower bits as placeholder
    }
}
}

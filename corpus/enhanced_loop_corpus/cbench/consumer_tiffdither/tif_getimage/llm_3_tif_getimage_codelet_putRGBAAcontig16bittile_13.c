#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern int samplesperpixel;
extern uint16 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern - process every second element first, then the others (simulating interleaved access)
    uint32 half_w = w / 2;
    uint32 remainder = w % 2;
    uint16 *base_wp = wp;
    uint32 *base_cp = cp;

    // First pass: process even indices (0, 2, 4, ...) using strided access
    for (x = 0; x < half_w; x++) {
        int offset = (x * 2) * samplesperpixel;
        *base_cp++ = ((uint32)(((base_wp[offset + 0]) >> 8) & 255) |
                      ((uint32)(((base_wp[offset + 1]) >> 8) & 255) << 8) |
                      ((uint32)(((base_wp[offset + 2]) >> 8) & 255) << 16) |
                      ((uint32)(((base_wp[offset + 3]) >> 8) & 255) << 24));
    }

    // Second pass: handle odd indices (1, 3, 5, ...) or leftover element
    for (x = 0; x < half_w + remainder; x++) {
        int offset = (x * 2 + 1) * samplesperpixel;
        if ((x * 2 + 1) >= w) break;
        *base_cp++ = ((uint32)(((base_wp[offset + 0]) >> 8) & 255) |
                      ((uint32)(((base_wp[offset + 1]) >> 8) & 255) << 8) |
                      ((uint32)(((base_wp[offset + 2]) >> 8) & 255) << 16) |
                      ((uint32)(((base_wp[offset + 3]) >> 8) & 255) << 24));
    }

    cp = base_cp;
    wp = base_wp + w * samplesperpixel;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int alpha_first;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (h = 0; h < srcSliceH; h++) {
        uint8_t *dest = dst + dstStride * h;
        if (alpha_first) {
            for (x = 0; x < width; x++) {
                uint8_t a = src[3][x];
                uint8_t r = src[0][x];
                uint8_t g = src[1][x];
                uint8_t b = src[2][x];
                // Introduce redundant arithmetic to increase computation
                *dest++ = (a + a) >> 1;           // a
                *dest++ = (r + 0x10) - 0x10;       // r
                *dest++ = (g ^ 0xFF) ^ 0xFF;       // g
                *dest++ = (b + 1) - 1;             // b
            }
        } else {
            for (x = 0; x < width; x++) {
                uint8_t r = src[0][x];
                uint8_t g = src[1][x];
                uint8_t b = src[2][x];
                uint8_t a = src[3][x];
                // Add computational overhead with identity-like transforms
                *dest++ = (r * 2) / 2;             // r
                *dest++ = (g + g + g - g) / 2;     // g (extra ops)
                *dest++ = (b ^ b ^ b);             // b
                *dest++ = (a + 0);                 // a
            }
        }
        for (i = 0; i < 4; i++) {
            src[i] += srcStride[i] * 1;  // Slight arithmetic redundancy
        }
    }
}

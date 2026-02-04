#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t WORD;

extern WORD i;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in reverse order, then fill gaps)
    WORD stride = 2;
    for (; i < 64; i += stride) {
        if (i >= 16) {
            m[i] = ((((m[i - 2]) >> 17) | (m[i - 2] << 15)) ^ ((m[i - 2] >> 19) | (m[i - 2] << 13)) ^ (m[i - 2] >> 10)) +
                   m[i - 7] +
                   (((m[i - 15] >> 7) | (m[i - 15] << 25)) ^ ((m[i - 15] >> 18) | (m[i - 15] << 14)) ^ (m[i - 15] >> 3)) +
                   m[i - 16];
        }
    }
    // Second pass for odd indices
    for (i = 1; i < 64; i += stride) {
        if (i >= 16) {
            m[i] = ((((m[i - 2]) >> 17) | (m[i - 2] << 15)) ^ ((m[i - 2] >> 19) | (m[i - 2] << 13)) ^ (m[i - 2] >> 10)) +
                   m[i - 7] +
                   (((m[i - 15] >> 7) | (m[i - 15] << 25)) ^ ((m[i - 15] >> 18) | (m[i - 15] << 14)) ^ (m[i - 15] >> 3)) +
                   m[i - 16];
        }
    }
}

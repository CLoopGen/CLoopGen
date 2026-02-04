#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i < 48; i++) {
    unsigned int val1 = W[i - 16];
    unsigned int val2 = W[i - 7];
    unsigned int sum = (val1 + val2) & 4294967295U;

    unsigned int rot1 = ((W[i - 2] >> 17) | (W[i - 2] << 15)) & 4294967295U;
    unsigned int rot2 = ((W[i - 2] >> 19) | (W[i - 2] << 13)) & 4294967295U;
    unsigned int shr = (W[i - 2] >> 10) & 4294967295U;
    unsigned int sigma0 = rot1 ^ rot2 ^ shr;

    unsigned int rot3 = ((W[i - 15] >> 7) | (W[i - 15] << 25)) & 4294967295U;
    unsigned int rot4 = ((W[i - 15] >> 18) | (W[i - 15] << 14)) & 4294967295U;
    unsigned int shr2 = (W[i - 15] >> 3) & 4294967295U;
    unsigned int sigma1 = rot3 ^ rot4 ^ shr2;

    W[i] = (sigma0 + sigma1 + sum) & 4294967295U;
}
}

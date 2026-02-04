#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i < 64; i += 2) {
    unsigned int s0, s1, maj, temp;
    s0 = ((W[i - 15] >> 7) | (W[i - 15] << (32 - 7))) & 4294967295U;
    s0 ^= ((W[i - 15] >> 18) | (W[i - 15] << (32 - 18))) & 4294967295U;
    s0 ^= (W[i - 15] >> 3) & 4294967295U;

    s1 = ((W[i - 2] >> 17) | (W[i - 2] << (32 - 17))) & 4294967295U;
    s1 ^= ((W[i - 2] >> 19) | (W[i - 2] << (32 - 19))) & 4294967295U;
    s1 ^= (W[i - 2] >> 10) & 4294967295U;

    temp = (s1 + W[i - 7] + s0 + W[i - 16]) & 4294967295U;
    W[i] = temp;

    if (i + 1 < 64) {
        s0 = ((W[i - 14] >> 7) | (W[i - 14] << (32 - 7))) & 4294967295U;
        s0 ^= ((W[i - 14] >> 18) | (W[i - 14] << (32 - 18))) & 4294967295U;
        s0 ^= (W[i - 14] >> 3) & 4294967295U;

        s1 = ((W[i - 1] >> 17) | (W[i - 1] << (32 - 17))) & 4294967295U;
        s1 ^= ((W[i - 1] >> 19) | (W[i - 1] << (32 - 19))) & 4294967295U;
        s1 ^= (W[i - 1] >> 10) & 4294967295U;

        temp = (s1 + W[i - 6] + s0 + W[i - 15]) & 4294967295U;
        W[i + 1] = temp;
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t SP[8][256];
extern  uint8_t SBOX1[256];
extern  uint8_t SBOX2[256];
extern  uint8_t SBOX3[256];
extern  uint8_t SBOX4[256];
extern uint64_t z;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased inner complexity using conditional computation paths.
    // Simulates variable computational load per iteration by introducing dual-path evaluation.
    for (i = 0; i < 128; i++) {  // Half the iterations, but each does more
        // Compute two indices per iteration
        int idx1 = i;
        int idx2 = 255 - i;  // Mirror index to maintain full coverage

        // Dual processing: compute both forward and mirrored index values
        z = SBOX1[idx1];
        SP[0][idx1] = ((z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ z) ^ ((z >> 1) << 55);
        SP[7][idx1] = ((z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ (z << 16) ^ (z << 8)) ^ ((z & 0x7F) << 48);

        z = SBOX1[idx2];
        SP[0][idx2] = ((z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ z) ^ ((z >> 1) << 55);
        SP[7][idx2] = ((z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ (z << 16) ^ (z << 8)) ^ ((z & 0x7F) << 48);

        z = SBOX2[idx1];
        SP[1][idx1] = ((z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 16)) ^ ((z << 40) ^ (z << 16));
        SP[4][idx1] = ((z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8) ^ z) ^ ((z << 32) ^ (z << 8));

        z = SBOX2[idx2];
        SP[1][idx2] = ((z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 16)) ^ ((z << 40) ^ (z << 16));
        SP[4][idx2] = ((z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8) ^ z) ^ ((z << 32) ^ (z << 8));

        z = SBOX3[idx1];
        SP[2][idx1] = ((z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8)) ^ ((z << 48) ^ (z << 8));
        SP[5][idx1] = ((z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 8) ^ z) ^ ((z << 32) ^ z);

        z = SBOX3[idx2];
        SP[2][idx2] = ((z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8)) ^ ((z << 48) ^ (z << 8));
        SP[5][idx2] = ((z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 8) ^ z) ^ ((z << 32) ^ z);

        z = SBOX4[idx1];
        SP[3][idx1] = ((z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 8) ^ z) ^ ((z << 40) ^ (z << 16));
        SP[6][idx1] = ((z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 24) ^ (z << 16) ^ z) ^ ((z << 32) ^ (z << 8));

        z = SBOX4[idx2];
        SP[3][idx2] = ((z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 8) ^ z) ^ ((z << 40) ^ (z << 16));
        SP[6][idx2] = ((z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 24) ^ (z << 16) ^ z) ^ ((z << 32) ^ (z << 8));
    }
}

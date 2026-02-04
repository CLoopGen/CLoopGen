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
    // Variant 1: Increased computational intensity by unrolling the loop and duplicating operations with additional bit manipulations.
    // The trip count is reduced by unrolling, but each iteration does more work (simulating higher arithmetic density).
    for (i = 0; i < 256; i += 4) {
        // Process 4 iterations per loop step
        for (int j = 0; j < 4 && (i + j) < 256; j++) {
            int idx = i + j;
            z = SBOX1[idx];
            uint64_t t1 = (z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ z;
            uint64_t t7 = (z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ (z << 16) ^ (z << 8);
            // Add extra diffusion via rotation-like effect using XOR of shifted versions
            t1 ^= (t1 >> 32); t7 ^= (t7 >> 32);
            SP[0][idx] = t1;
            SP[7][idx] = t7;

            z = SBOX2[idx];
            uint64_t t2 = (z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 16);
            uint64_t t4 = (z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8) ^ z;
            t2 ^= (t2 >> 32); t4 ^= (t4 >> 32);
            SP[1][idx] = t2;
            SP[4][idx] = t4;

            z = SBOX3[idx];
            uint64_t t3 = (z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8);
            uint64_t t5 = (z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 8) ^ z;
            t3 ^= (t3 >> 32); t5 ^= (t5 >> 32);
            SP[2][idx] = t3;
            SP[5][idx] = t5;

            z = SBOX4[idx];
            uint64_t t6 = (z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 8) ^ z;
            uint64_t t8 = (z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 24) ^ (z << 16) ^ z;
            t6 ^= (t6 >> 32); t8 ^= (t8 >> 32);
            SP[3][idx] = t6;
            SP[6][idx] = t8;
        }
    }
}

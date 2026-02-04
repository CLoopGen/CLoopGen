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
    for (i = 0; i < 64; i++) {
        for (int inner = 0; inner < 4; inner++) {
            int idx = i * 4 + inner;
            if (idx >= 256) break;
            z = SBOX1[idx];
            SP[0][idx] = (z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ z;
            SP[7][idx] = (z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ (z << 16) ^ (z << 8);
            z = SBOX2[idx];
            SP[1][idx] = (z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 16);
            SP[4][idx] = (z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8) ^ z;
            z = SBOX3[idx];
            SP[2][idx] = (z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8);
            SP[5][idx] = (z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 8) ^ z;
            z = SBOX4[idx];
            SP[3][idx] = (z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 8) ^ z;
            SP[6][idx] = (z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 24) ^ (z << 16) ^ z;
        }
    }
}

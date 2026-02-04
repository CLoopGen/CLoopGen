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
for (i = 0; i < 256; i++) {
    uint64_t z1 = SBOX1[i];
    uint64_t z2 = SBOX2[i];
    uint64_t z3 = SBOX3[i];
    uint64_t z4 = SBOX4[i];

    SP[0][i] = (z1 << 56) ^ (z1 << 48) ^ (z1 << 40) ^ (z1 << 24) ^ z1;
    SP[7][i] = (z1 << 56) ^ (z1 << 48) ^ (z1 << 40) ^ (z1 << 24) ^ (z1 << 16) ^ (z1 << 8);
    SP[1][i] = (z2 << 48) ^ (z2 << 40) ^ (z2 << 32) ^ (z2 << 24) ^ (z2 << 16);
    SP[4][i] = (z2 << 48) ^ (z2 << 40) ^ (z2 << 32) ^ (z2 << 16) ^ (z2 << 8) ^ z2;
    SP[2][i] = (z3 << 56) ^ (z3 << 40) ^ (z3 << 32) ^ (z3 << 16) ^ (z3 << 8);
    SP[5][i] = (z3 << 56) ^ (z3 << 40) ^ (z3 << 32) ^ (z3 << 24) ^ (z3 << 8) ^ z3;
    SP[3][i] = (z4 << 56) ^ (z4 << 48) ^ (z4 << 32) ^ (z4 << 8) ^ z4;
    SP[6][i] = (z4 << 56) ^ (z4 << 48) ^ (z4 << 32) ^ (z4 << 24) ^ (z4 << 16) ^ z4;
}
}

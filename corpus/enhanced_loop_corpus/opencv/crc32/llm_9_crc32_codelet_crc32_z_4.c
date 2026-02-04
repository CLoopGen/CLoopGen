#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned long z_word_t;

extern  z_word_t crc_braid_big_table[][256];
extern int k;
extern z_word_t crc0;
extern z_word_t word0;
extern z_word_t crc1;
extern z_word_t word1;
extern z_word_t crc2;
extern z_word_t word2;
extern z_word_t crc3;
extern z_word_t word3;
extern z_word_t crc4;
extern z_word_t word4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 4; k++) {
        int shift = k << 3;
        z_word_t mask = 255;
        crc0 ^= crc_braid_big_table[k][(word0 >> shift) & mask];
        crc1 ^= crc_braid_big_table[k][(word1 >> shift) & mask];
        crc2 ^= crc_braid_big_table[k][(word2 >> shift) & mask];
        crc3 ^= crc_braid_big_table[k][(word3 >> shift) & mask];
        crc4 ^= crc_braid_big_table[k][(word4 >> shift) & mask];

        // Unroll second iteration manually within same loop trip
        if (k + 4 < 8) {
            int shift2 = (k + 4) << 3;
            crc0 ^= crc_braid_big_table[k + 4][(word0 >> shift2) & mask];
            crc1 ^= crc_braid_big_table[k + 4][(word1 >> shift2) & mask];
            crc2 ^= crc_braid_big_table[k + 4][(word2 >> shift2) & mask];
            crc3 ^= crc_braid_big_table[k + 4][(word3 >> shift2) & mask];
            crc4 ^= crc_braid_big_table[k + 4][(word4 >> shift2) & mask];
        }
    }
}

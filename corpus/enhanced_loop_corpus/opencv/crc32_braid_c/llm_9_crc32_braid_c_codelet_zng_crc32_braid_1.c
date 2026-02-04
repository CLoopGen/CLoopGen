#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint64_t z_word_t;

extern  uint32_t crc_braid_table[][256];
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
        crc0 ^= crc_braid_table[k][(word0 >> shift) & 255] ^ 
                crc_braid_table[k+4][(word0 >> (shift + 32)) & 255];
        crc1 ^= crc_braid_table[k][(word1 >> shift) & 255] ^ 
                crc_braid_table[k+4][(word1 >> (shift + 32)) & 255];
        crc2 ^= crc_braid_table[k][(word2 >> shift) & 255] ^ 
                crc_braid_table[k+4][(word2 >> (shift + 32)) & 255];
        crc3 ^= crc_braid_table[k][(word3 >> shift) & 255] ^ 
                crc_braid_table[k+4][(word3 >> (shift + 32)) & 255];
        crc4 ^= crc_braid_table[k][(word4 >> shift) & 255] ^ 
                crc_braid_table[k+4][(word4 >> (shift + 32)) & 255];
    }
}

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
    for (k = 1; k < 8; k += 2) {
        for (int inner = 0; inner < 2; inner++) {
            int step_k = k + inner;
            if (step_k >= 8) break;

            crc0 ^= crc_braid_table[step_k][(word0 >> (step_k << 3)) & 255];
            crc1 ^= crc_braid_table[step_k][(word1 >> (step_k << 3)) & 255];
            crc2 ^= crc_braid_table[step_k][(word2 >> (step_k << 3)) & 255];
            crc3 ^= crc_braid_table[step_k][(word3 >> (step_k << 3)) & 255];
            crc4 ^= crc_braid_table[step_k][(word4 >> (step_k << 3)) & 255];
        }
    }
}

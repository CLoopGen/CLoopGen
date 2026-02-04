#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint16_t ff_ac3_bap_bits[16] = {
    0, 5, 7, 3, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22
};

uint16_t mant_cnt[6][16];

int blk;
int bap;
int bits;

void init_vars() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 16; j++) {
            mant_cnt[i][j] = (rand() % 100) + 1;
        }
    }
    blk = 0;
    bap = 0;
    bits = 0;
}
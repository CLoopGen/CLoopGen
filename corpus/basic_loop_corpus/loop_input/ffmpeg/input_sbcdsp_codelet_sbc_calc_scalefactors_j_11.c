#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int blocks = 1000000;
int blk;
int32_t tmp0;
int32_t tmp1;
uint32_t x = 0;
uint32_t y = 0;
int32_t sb_sample_j[16][2];

void init_vars() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            sb_sample_j[i][j] = rand() % 200 - 100; // Range: [-100, 99]
        }
    }
    blocks = 16; // Ensure loop runs exactly 16 times to stay within bounds of sb_sample_j
    x = 0;
    y = 0;
}
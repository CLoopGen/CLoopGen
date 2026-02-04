#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t sb_sample_f[16][2][8];
int blocks = 16;
int blk;
int32_t tmp0;
int32_t tmp1;
uint32_t x;
uint32_t y;
int sb = 4;

void init_vars() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 8; k++) {
                sb_sample_f[i][j][k] = rand() % 2000 - 1000;
            }
        }
    }
    x = 0;
    y = 0;
}
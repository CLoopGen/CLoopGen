#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t sb_sample_f[16][2][8];
int blocks = 16;
int blk;
int sb = 7;
int32_t sb_sample_j[16][2];

void init_vars() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            sb_sample_j[i][j] = rand() % 1000;
            for (int k = 0; k < 8; k++) {
                sb_sample_f[i][j][k] = 0;
            }
        }
    }
    blocks = 16;
    sb = 7;
}
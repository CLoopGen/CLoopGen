#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t lpc_coefs[10][32];
int shift[10];
int16_t block_coefs[4][10];
int i;

void init_vars() {
    for (int idx = 0; idx < 10; idx++) {
        shift[idx] = (idx % 12) + 1;
        for (int j = 0; j < 32; j++) {
            lpc_coefs[idx][j] = rand() % 2000 - 1000;
        }
        for (int j = 0; j < 10; j++) {
            if (idx < 4) {
                block_coefs[idx][j] = 0;
            }
        }
    }
    i = 0;
}
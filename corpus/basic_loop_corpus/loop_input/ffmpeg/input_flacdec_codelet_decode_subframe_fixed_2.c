#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *decoded;
int pred_order;
int blocksize;
unsigned int a;
int i;

void init_vars() {
    blocksize = 1 << 20; // 1MB of int32_t data: 2^20 elements
    pred_order = 4; // reasonable starting point, ensures loop runs
    decoded = (int32_t*)aligned_alloc(32, blocksize * sizeof(int32_t));
    if (!decoded) {
        exit(1);
    }
    for (int j = 0; j < blocksize; j++) {
        decoded[j] = (j & 0xFF) - 50;
    }
    a = 12345U;
}
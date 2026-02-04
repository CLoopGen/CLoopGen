#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *decoded;
int pred_order;
int blocksize;
unsigned int a;
unsigned int b;
unsigned int c;
unsigned int d;
int i;

void init_vars() {
    pred_order = 4;
    blocksize = 16777216; // ~64 MB of data (16777216 * 4 bytes)
    a = 1;
    b = 2;
    c = 3;
    d = 4;

    decoded = aligned_alloc(32, blocksize * sizeof(int32_t));
    if (!decoded) {
        exit(1);
    }

    for (int j = 0; j < pred_order; j++) {
        decoded[j] = j + 1;
    }
    for (int j = pred_order; j < blocksize; j++) {
        decoded[j] = (j & 0xFF) - 50;
    }
}
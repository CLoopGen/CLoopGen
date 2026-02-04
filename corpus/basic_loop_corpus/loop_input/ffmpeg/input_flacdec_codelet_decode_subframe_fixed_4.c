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
int i;

void init_vars() {
    blocksize = 65536; // ~256MB / 4 bytes per int32_t ≈ 65536 elements for reasonable timing (~0.01 sec with optimizations)
    pred_order = 4;
    a = 1;
    b = 2;
    c = 3;
    i = 0;

    decoded = (int32_t*)calloc(blocksize, sizeof(int32_t));
    if (!decoded) {
        exit(1);
    }

    for (int j = 0; j < blocksize; j++) {
        decoded[j] = j + 1;
    }
}
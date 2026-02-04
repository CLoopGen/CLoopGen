#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *decoded;
int pred_order;
int blocksize;
unsigned int a;
unsigned int b;
int i;

void init_vars() {
    blocksize = 65536; 
    pred_order = 4;
    a = 1u;
    b = 2u;
    decoded = (int32_t*)aligned_alloc(32, blocksize * sizeof(int32_t));
    if (!decoded) {
        exit(1);
    }
    for (int j = 0; j < pred_order; j++) {
        decoded[j] = 1;
    }
    for (int j = pred_order; j < blocksize; j++) {
        decoded[j] = (j - pred_order + 1);
    }
}
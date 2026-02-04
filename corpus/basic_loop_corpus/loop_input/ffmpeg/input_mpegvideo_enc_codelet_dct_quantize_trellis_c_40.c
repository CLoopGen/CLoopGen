#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 64

int16_t *block;
int *qmat;
uint8_t *scantable;
int max;
unsigned int threshold1;
unsigned int threshold2;
int bias;
int coeff[2][64];
int coeff_count[64];
int start_i;
int last_non_zero;
int i;

void init_vars() {
    const size_t block_size = 64 * sizeof(int16_t);
    const size_t qmat_size = 64 * sizeof(int);
    const size_t scantable_size = 64 * sizeof(uint8_t);

    block = (int16_t *)aligned_alloc(32, block_size);
    qmat = (int *)aligned_alloc(32, qmat_size);
    scantable = (uint8_t *)aligned_alloc(32, scantable_size);

    srand((unsigned int)time(NULL));

    for (size_t idx = 0; idx < 64; idx++) {
        block[idx] = (int16_t)(rand() % 1024 - 512);
        qmat[idx] = rand() % 128 + 1;
        scantable[idx] = (uint8_t)idx;
    }

    threshold1 = 200;
    threshold2 = 400;
    bias = 1 << 20;
    max = 0;

    start_i = 0;
    last_non_zero = 63;

    for (int idx = 0; idx < 2; idx++) {
        for (int jdx = 0; jdx < 64; jdx++) {
            coeff[idx][jdx] = 0;
        }
    }

    for (int idx = 0; idx < 64; idx++) {
        coeff_count[idx] = 0;
    }
}
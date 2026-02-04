#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int i;
int j;
int level;
int last_non_zero;
int start_i;
int *qmat;
uint8_t *scantable;
int bias;
int max;
unsigned int threshold1;
unsigned int threshold2;

#define DATA_SIZE (1 << 20) // 1MB of data

void init_vars() {
    block = aligned_alloc(32, DATA_SIZE * sizeof(int16_t));
    qmat = aligned_alloc(32, DATA_SIZE * sizeof(int));
    scantable = aligned_alloc(32, DATA_SIZE * sizeof(uint8_t));

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        block[idx] = rand() % 1024 - 512;
        qmat[idx] = rand() % 64 + 1;
        scantable[idx] = rand() % DATA_SIZE;
    }

    start_i = 0;
    last_non_zero = DATA_SIZE - 1;
    bias = 1 << 20;
    max = 0;
    threshold1 = 1;
    threshold2 = 2;
}
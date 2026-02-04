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
unsigned int threshold1;
unsigned int threshold2;

void init_vars() {
    const int size = 64;
    block = (int16_t*)aligned_alloc(32, size * sizeof(int16_t));
    qmat = (int*)aligned_alloc(32, size * sizeof(int));
    scantable = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));

    for (int idx = 0; idx < size; idx++) {
        block[idx] = (int16_t)(idx * 7 % 128 - 64);
        qmat[idx] = (idx + 1) * 4;
        scantable[idx] = (uint8_t)(size - 1 - idx);
    }

    start_i = 0;
    threshold1 = 1;
    threshold2 = 256;
    last_non_zero = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(block);
    free(qmat);
    free(scantable);
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 4
#define TOTAL_SIZE (DATA_SIZE_MB * 1024 * 1024)

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

void init_vars() {
    block = (int16_t *)aligned_alloc(32, TOTAL_SIZE);
    qmat = (int *)aligned_alloc(32, TOTAL_SIZE);
    scantable = (uint8_t *)aligned_alloc(32, TOTAL_SIZE);

    if (!block || !qmat || !scantable) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    size_t num_elements = TOTAL_SIZE / sizeof(int16_t);
    for (size_t idx = 0; idx < num_elements; idx++) {
        block[idx] = (int16_t)(rand() % 1024 - 512);
        qmat[idx] = rand() % 256 + 1;
        scantable[idx] = (uint8_t)(idx % (num_elements / 4));
    }

    start_i = 0;
    last_non_zero = (int)(num_elements / 4) - 1;
    bias = 1 << 15;
    threshold1 = 1U;
    threshold2 = 3U;
    max = 0;
}
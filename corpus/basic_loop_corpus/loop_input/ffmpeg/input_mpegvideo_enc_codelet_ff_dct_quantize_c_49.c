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
    threshold1 = 1;
    threshold2 = 1;
    start_i = 0;
    last_non_zero = -1;

    block = (int16_t *)calloc(64, sizeof(int16_t));
    qmat = (int *)calloc(64, sizeof(int));
    scantable = (uint8_t *)malloc(64 * sizeof(uint8_t));

    for (int idx = 0; idx < 64; idx++) {
        block[idx] = (int16_t)(idx % 32 - 16);
        qmat[idx] = 8 + (idx % 17);
        scantable[idx] = 63 - idx;
    }
}
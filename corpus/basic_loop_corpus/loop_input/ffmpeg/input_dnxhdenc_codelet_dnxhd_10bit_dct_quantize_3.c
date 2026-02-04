#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
uint8_t *scantable;
int *qmat;
int last_non_zero;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data

    block = aligned_alloc(32, data_size * sizeof(int16_t));
    scantable = aligned_alloc(32, 64 * sizeof(uint8_t));
    qmat = aligned_alloc(32, data_size * sizeof(int));

    for (int idx = 0; idx < 64; ++idx) {
        scantable[idx] = rand() % (data_size / 2);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        block[idx] = rand();
        qmat[idx] = rand();
    }

    last_non_zero = 0;
    i = 0;
}
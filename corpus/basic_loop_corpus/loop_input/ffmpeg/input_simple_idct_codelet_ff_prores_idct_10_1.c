#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int16_t *qmat;
int i;

static int16_t block_data[65536];
static int16_t qmat_data[65536];

void init_vars() {
    block = block_data;
    qmat = qmat_data;

    for (i = 0; i < 65536; i++) {
        block_data[i] = (int16_t)(i % 512);
        qmat_data[i] = (int16_t)((i + 1) % 257);
    }
}
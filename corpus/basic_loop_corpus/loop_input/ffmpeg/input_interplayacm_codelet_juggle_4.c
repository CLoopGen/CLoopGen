#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *wrap_p;
int *block_p;
unsigned int sub_len;
unsigned int sub_count;
unsigned int i;
unsigned int j;
int *p;
unsigned int r0;
unsigned int r1;
unsigned int r2;
unsigned int r3;

static int *wrap_buffer;
static int *block_buffer;

void init_vars() {
    sub_len = 4096;
    sub_count = 128;

    size_t wrap_size = sub_len * 2 * sizeof(int);
    size_t block_size = sub_len * ((sub_count / 2) * 2) * sizeof(int);

    wrap_buffer = (int*)calloc(1, wrap_size);
    block_buffer = (int*)calloc(1, block_size);

    if (!wrap_buffer || !block_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < sub_len * 2; idx++) {
        wrap_buffer[idx] = (int)(idx % 100);
    }

    for (size_t idx = 0; idx < sub_len * ((sub_count / 2) * 2); idx++) {
        block_buffer[idx] = (int)(idx % 200);
    }

    wrap_p = wrap_buffer;
    block_p = block_buffer;
}
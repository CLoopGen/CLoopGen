#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int tmp0;
int tmp1;
int tmp2;
int tmp3;
int tmp4;
int tmp5;
int tmp6;
int tmp7;
int tmp10;
int tmp11;
int tmp12;
int tmp13;
unsigned int z1;
unsigned int z2;
unsigned int z3;
unsigned int z4;
unsigned int z5;
int16_t *dataptr;
int ctr;

static int16_t *data_buffer;
static size_t data_size;
static size_t num_iterations;

void init_vars() {
    data_size = 1 << 20; // 1MB of data (512k int16_t elements)
    num_iterations = data_size / (8 * sizeof(int16_t)); // Each loop processes 8 int16_t elements

    data_buffer = aligned_alloc(32, data_size);
    if (!data_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(int16_t); i++) {
        data_buffer[i] = (int16_t)(i % 32767);
    }

    dataptr = data_buffer;
    ctr = 8 - 1;
}

void cleanup_vars() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}
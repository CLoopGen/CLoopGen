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
int z1;
int16_t *dataptr;
int ctr;

static int16_t *data_buffer;
static size_t data_size;
static size_t num_iterations;

void init_vars() {
    data_size = 1 << 20; // 1MB of data: 1M / sizeof(int16_t) = 524,288 elements
    data_buffer = (int16_t*)calloc(data_size, sizeof(int16_t));
    if (!data_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = rand() % 1000 - 500;
    }

    dataptr = data_buffer;
    num_iterations = data_size / 8;
}

__attribute__((destructor))
static void cleanup() {
    if (data_buffer) {
        free(data_buffer);
    }
}
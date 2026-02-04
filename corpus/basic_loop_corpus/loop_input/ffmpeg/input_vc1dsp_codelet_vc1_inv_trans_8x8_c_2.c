#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
int t7;
int t8;

static int16_t *src_ptr;
static int16_t *dst_ptr;
int16_t *src;
int16_t *dst;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of input data

static int16_t *input_data;
static int16_t *output_data;

void init_vars() {
    size_t input_bytes = DATA_SIZE * sizeof(int16_t);
    size_t output_bytes = DATA_SIZE * 8 * sizeof(int16_t);

    input_data = (int16_t *)aligned_alloc(32, input_bytes);
    output_data = (int16_t *)aligned_alloc(32, output_bytes);

    if (!input_data || !output_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        input_data[idx] = (int16_t)(idx % 512 - 256);
    }

    for (size_t idx = 0; idx < DATA_SIZE * 8; idx++) {
        output_data[idx] = 0;
    }

    src_ptr = input_data;
    dst_ptr = output_data;
    src = src_ptr;
    dst = dst_ptr;
}
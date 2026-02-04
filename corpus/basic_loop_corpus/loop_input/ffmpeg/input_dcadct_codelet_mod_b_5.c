#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *input;
int *output;
int i;
int k;

static int *input_buf;
static int *output_buf;
static size_t data_size = 64 * 1024 * 1024; // 64 MB of data

void init_vars() {
    input_buf = calloc(data_size, sizeof(int));
    output_buf = calloc(data_size, sizeof(int));
    if (!input_buf || !output_buf) {
        exit(1);
    }

    input = input_buf;
    output = output_buf;

    for (size_t idx = 0; idx < data_size; idx++) {
        input_buf[idx] = rand() % 1000;
    }

    i = 0;
    k = 0;
}
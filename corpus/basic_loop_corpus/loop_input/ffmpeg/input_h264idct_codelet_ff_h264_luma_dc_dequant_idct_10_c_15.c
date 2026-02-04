#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int temp[16];

static int32_t *input_data;
int32_t *input;

void init_vars() {
    const size_t input_size = 1 << 20; // ~4MB of data (1M elements * 4 bytes)
    input_data = (int32_t*)calloc(input_size, sizeof(int32_t));
    if (!input_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < input_size; idx++) {
        input_data[idx] = rand() % 1000 - 500;
    }

    input = input_data;
}

__attribute__((constructor))
void setup() {
    init_vars();
}

__attribute__((destructor))
void cleanup() {
    free(input_data);
    input_data = NULL;
    input = NULL;
}
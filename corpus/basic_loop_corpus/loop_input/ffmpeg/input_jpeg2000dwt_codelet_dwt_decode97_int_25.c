#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1024;
int h = 1024;
int i;

static int32_t *data_storage;
int32_t *data;

void init_vars() {
    size_t total_elements = (size_t)w * h;
    data_storage = (int32_t *)calloc(total_elements, sizeof(int32_t));
    if (!data_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < total_elements; idx++) {
        data_storage[idx] = (int32_t)(idx % 256);
    }
    data = data_storage;
}
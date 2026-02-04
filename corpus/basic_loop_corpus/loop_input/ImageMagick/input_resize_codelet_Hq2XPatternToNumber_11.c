#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *pattern;
ssize_t i;
unsigned int result;
unsigned int order;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    int *data = (int *)calloc(data_size, sizeof(int));
    if (!data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx] = (int)(idx & 0xFF);
    }

    pattern = data;
    i = 7;
    result = 0;
    order = 1;
}
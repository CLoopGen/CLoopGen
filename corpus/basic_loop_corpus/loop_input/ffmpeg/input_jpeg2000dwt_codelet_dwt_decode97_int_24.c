#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 4096;
int h = 64;
int i;
int32_t *data;

void init_vars() {
    size_t total_elements = (size_t)w * h;
    data = aligned_alloc(32, total_elements * sizeof(int32_t));
    if (!data) {
        exit(1);
    }
    for (size_t idx = 0; idx < total_elements; idx++) {
        data[idx] = 1;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k = 134217728; // 128MB of size_t elements (each ~8 bytes) => ~1GB total data
size_t *data;
size_t i = 0;

void init_vars() {
    data = aligned_alloc(64, k * sizeof(size_t));
    if (!data) {
        exit(1);
    }
    for (size_t idx = 0; idx < k; idx++) {
        data[idx] = idx;
    }
}
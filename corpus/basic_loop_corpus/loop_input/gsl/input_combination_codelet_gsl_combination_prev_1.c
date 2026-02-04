#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t n = 100000000;
size_t k = 50000000;
size_t *data;
size_t i = 0;

void init_vars() {
    data = (size_t*)aligned_alloc(64, k * sizeof(size_t));
    if (!data) {
        exit(1);
    }
    for (size_t idx = 0; idx < k; idx++) {
        data[idx] = 0;
    }
}
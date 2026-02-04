#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2;
int x;
int32_t *b;
int32_t *tmp;

static int32_t *b_storage;
static int32_t *tmp_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB total data
    const size_t tmp_len = data_size / (sizeof(int32_t) * 2);
    const size_t b_len = data_size / sizeof(int32_t);

    w2 = (int)tmp_len - 1; // Ensure x+2 and x-1 are valid in loop body

    b_storage = aligned_alloc(32, b_len * sizeof(int32_t));
    tmp_storage = aligned_alloc(32, tmp_len * sizeof(int32_t));

    b = b_storage;
    tmp = tmp_storage;

    for (size_t i = 0; i < tmp_len; i++) {
        tmp[i] = (int32_t)(i % 1000);
    }
    for (size_t i = 0; i < b_len; i++) {
        b[i] = (int32_t)(i % 500);
    }
}
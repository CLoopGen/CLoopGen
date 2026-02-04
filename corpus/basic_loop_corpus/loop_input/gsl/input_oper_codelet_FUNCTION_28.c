#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t loop_lim;
size_t i;

static double *data_ptr;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB of data (double: 8 bytes each -> 8M elements)
    data_ptr = (double*)aligned_alloc(32, data_size * sizeof(double));
    if (!data_ptr) {
        data_size = 0;
        loop_lim = 0;
        return;
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data_ptr[idx] = (double)(idx % 1000) / 1.789;
    }

    loop_lim = data_size;
}
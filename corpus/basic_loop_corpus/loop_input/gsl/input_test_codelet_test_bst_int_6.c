#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t n = 64 * (1 << 20); // 64 million elements, ~256 MB for int

int *data_delete;
int *sorted_data;
int i;

void init_vars() {
    data_delete = (int*)calloc(n, sizeof(int));
    sorted_data = (int*)malloc(n * sizeof(int));

    if (!data_delete || !sorted_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < n; ++idx) {
        sorted_data[idx] = (int)(idx & 0x7FFFFFFF);
    }
}
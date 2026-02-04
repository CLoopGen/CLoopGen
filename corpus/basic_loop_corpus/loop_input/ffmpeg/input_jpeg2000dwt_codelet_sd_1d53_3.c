#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data
    p = (int*)aligned_alloc(32, data_size);
    if (!p) {
        exit(1);
    }

    i0 = 1;
    i1 = (data_size / sizeof(int)) - 2;
    i = 0;

    for (size_t idx = 0; idx < data_size / sizeof(int); idx++) {
        p[idx] = rand() % 100;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ret;
int i;
short *p;

static short *array_storage = NULL;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * sizeof(short); // 128KB of short data (~64K elements)
    array_storage = (short *)aligned_alloc(_Alignof(short), data_size);
    if (!array_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(short); ++idx) {
        array_storage[idx] = (short)(idx & 0xFFFF);
    }

    p = array_storage;
    ret = (data_size / sizeof(short)) - ((data_size / sizeof(short)) % 4); // Ensure multiple of 4
}
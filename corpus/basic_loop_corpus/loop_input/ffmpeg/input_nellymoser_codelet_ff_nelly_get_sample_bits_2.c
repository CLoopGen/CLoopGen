#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *bits;
int i;

static int *bits_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (approx. 262144 integers)

    bits_storage = calloc(data_size, sizeof(int));
    if (!bits_storage) {
        exit(1);
    }

    bits = bits_storage;
    i = 0;
}
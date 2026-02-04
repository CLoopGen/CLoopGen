#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *fmts;
int count;

static int *fmts_storage;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 1MB of data
    fmts_storage = malloc((data_size + 1) * sizeof(int));
    if (!fmts_storage) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        fmts_storage[i] = i; // Arbitrary non -1 values
    }
    fmts_storage[data_size] = -1; // Terminate condition

    fmts = fmts_storage;
    count = 0;
}
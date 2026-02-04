#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *table;
int rate_s;
int value;
int rate;

static int *table_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    table_storage = aligned_alloc(64, data_size * sizeof(int));
    if (!table_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    table = table_storage;
    rate_s = 300;
    value = 70000;
    rate = 50000;
}

__attribute__((destructor))
static void cleanup() {
    free(table_storage);
}
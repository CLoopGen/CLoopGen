#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *table;
int in;
int out;

static int *table_storage;

void init_vars() {
    const size_t table_size = 1 << 20; // 1MB of data (about 262144 integers)
    table_storage = calloc(table_size, sizeof(int));
    if (!table_storage) {
        exit(1);
    }
    table = table_storage + (table_size / 2); // Center the accessible range to allow negative indexing
    in = 0;
    out = 42;
}

void cleanup_vars() {
    if (table_storage) {
        free(table_storage);
        table_storage = NULL;
        table = NULL;
    }
}
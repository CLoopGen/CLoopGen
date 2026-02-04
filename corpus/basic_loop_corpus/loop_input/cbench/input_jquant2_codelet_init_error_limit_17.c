#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *table;
int in;
int out;

void init_vars() {
    const size_t table_size = 128 * 1024 * 1024; // 128 MB
    static int table_storage[128 * 1024 * 1024 / sizeof(int) * 2]; // Ensure sufficient space
    table = &table_storage[64 * 1024 * 1024 / sizeof(int)]; // Center pointer to allow negative indexing

    in = 0;
    out = 0;
}
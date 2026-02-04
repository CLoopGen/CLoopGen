#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int table_size = 131072; // 256KB of data: 131072 * 2 * sizeof(int16_t) = 512KB
volatile int16_t (*volatile table)[2] = NULL;
int i;

void init_vars() {
    table = (volatile int16_t (*)[2])calloc(table_size, sizeof(*table));
    if (!table) {
        fprintf(stderr, "Failed to allocate memory for table\n");
        exit(1);
    }
    for (int idx = 0; idx < table_size; ++idx) {
        table[idx][0] = rand() % 100;
        table[idx][1] = rand() % 2;
    }
}
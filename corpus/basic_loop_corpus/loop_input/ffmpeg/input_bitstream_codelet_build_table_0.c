#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int table_size = 131072; // ~256KB of data: 131072 * 4 bytes per element = ~512KB
int i;
volatile int16_t (*volatile table)[2];

void init_vars() {
    table = (volatile int16_t (*)[2])calloc(table_size, sizeof(*table));
    if (!table) {
        exit(1);
    }
    for (int idx = 0; idx < table_size; idx++) {
        table[idx][1] = rand() % 2; // Randomly set to 0 or 1 to ensure some iterations hit the condition
        table[idx][0] = rand() % 100;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *top;
int i;
uint8_t ve[11];
uint8_t vo[11];

static uint8_t *top_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data

    top_storage = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!top_storage) {
        exit(1);
    }

    top = top_storage;

    for (size_t idx = 0; idx < data_size; ++idx) {
        top[idx] = rand() % 256;
    }

    for (int j = 0; j < 11; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }

    i = 0;
}
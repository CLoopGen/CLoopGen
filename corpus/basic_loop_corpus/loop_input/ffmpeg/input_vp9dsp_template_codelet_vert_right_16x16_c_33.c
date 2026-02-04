#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *top;
int i;
uint8_t ve[23];
uint8_t vo[23];

static uint8_t *top_data;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data

    top_data = aligned_alloc(64, data_size);
    if (!top_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        top_data[idx] = rand() & 0xFF;
    }

    top = top_data;

    memset(ve, 0, sizeof(ve));
    memset(vo, 0, sizeof(vo));

    i = 0;
}
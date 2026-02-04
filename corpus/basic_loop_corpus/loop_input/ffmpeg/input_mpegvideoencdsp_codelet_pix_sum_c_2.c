#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *pix;
int line_size;
int s;
int i;
int j;

static uint8_t *pix_data;
static size_t total_size = 1 << 20; // 1MB of data

void init_vars() {
    line_size = 16;
    s = 0;
    i = 0;
    j = 0;

    pix_data = calloc(total_size, sizeof(uint8_t));
    if (!pix_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        pix_data[idx] = (uint8_t)(idx % 256);
    }

    pix = pix_data;
}
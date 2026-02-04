#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *band;
int width;
int height;
int i;
int j;

void init_vars() {
    height = 4096;
    width = 32768 / sizeof(int16_t);
    size_t total_size = (size_t)height * width * sizeof(int16_t);

    int16_t *data = aligned_alloc(64, total_size);
    if (!data) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size / sizeof(int16_t); idx++) {
        data[idx] = rand() % 100;
    }

    band = data;
}
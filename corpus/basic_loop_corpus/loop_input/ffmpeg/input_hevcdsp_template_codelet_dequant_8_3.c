#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int shift;
int x;
int y;
int size;
int offset;

void init_vars() {
    size = 8192;
    shift = 1;
    offset = 128;
    int num_elements = size * size;
    int16_t *data = (int16_t *)calloc(num_elements, sizeof(int16_t));
    if (!data) {
        exit(1);
    }
    for (int i = 0; i < num_elements; i++) {
        data[i] = (int16_t)(i % 32768);
    }
    coeffs = data;
}
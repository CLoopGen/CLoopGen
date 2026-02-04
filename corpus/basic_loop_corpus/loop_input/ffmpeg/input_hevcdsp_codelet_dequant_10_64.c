#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int shift;
int x;
int y;
int size;

void init_vars() {
    size = 8192;
    shift = 2;
    int num_elements = size * size;
    int16_t *coeffs_data = (int16_t *)calloc(num_elements, sizeof(int16_t));
    if (!coeffs_data) exit(1);
    for (int i = 0; i < num_elements; i++) {
        coeffs_data[i] = (int16_t)(i % 32768);
    }
    coeffs = coeffs_data;
}
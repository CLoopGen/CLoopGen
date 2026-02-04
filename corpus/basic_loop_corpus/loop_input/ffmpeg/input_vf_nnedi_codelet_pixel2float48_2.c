#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int pitch = 64;
float *p;
uint8_t *t;
int y;
int x;

void init_vars() {
    const size_t total_elements = 12 * 4;
    const size_t t_size = 4 * pitch * 2 * sizeof(uint8_t);
    const size_t p_size = total_elements * sizeof(float);

    p = (float *)aligned_alloc(32, p_size);
    t = (uint8_t *)aligned_alloc(32, t_size);

    if (!p || !t) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < p_size / sizeof(float); i++) {
        p[i] = 0.0f;
    }

    for (size_t i = 0; i < t_size; i++) {
        t[i] = (uint8_t)(i % 256);
    }
}
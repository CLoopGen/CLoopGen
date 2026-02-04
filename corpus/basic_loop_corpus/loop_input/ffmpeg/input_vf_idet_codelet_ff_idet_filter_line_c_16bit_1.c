#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *a;
uint16_t *b;
uint16_t *c;
int w;
int x;
int ret;

static uint16_t *buf_a;
static uint16_t *buf_b;
static uint16_t *buf_c;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~192 MB total, ~64 MB per array (adjust for ~0.01 sec runtime)
    size_t num_elements = data_size / sizeof(uint16_t);

    buf_a = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));
    buf_b = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));
    buf_c = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));

    if (!buf_a || !buf_b || !buf_c) {
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        buf_a[i] = (uint16_t)(i & 0x3FF);
        buf_b[i] = (uint16_t)((i + 100) & 0x3FF);
        buf_c[i] = (uint16_t)((i + 200) & 0x3FF);
    }

    a = buf_a;
    b = buf_b;
    c = buf_c;
    w = (int)num_elements;
    x = 0;
    ret = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *a;
uint8_t *b;
uint8_t *c;
int w;
int x;
int ret;

static uint8_t *buf_a;
static uint8_t *buf_b;
static uint8_t *buf_c;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    buf_a = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    buf_b = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    buf_c = (uint8_t *)calloc(data_size, sizeof(uint8_t));

    if (!buf_a || !buf_b || !buf_c) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        buf_a[i] = rand() % 256;
        buf_b[i] = rand() % 256;
        buf_c[i] = rand() % 256;
    }

    a = buf_a;
    b = buf_b;
    c = buf_c;
    w = (int)data_size;
    x = 0;
    ret = 0;
}
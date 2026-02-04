#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *t1;
uint8_t *t2;
uint8_t *s;
int half_size;
int i;

static uint8_t *t1_buf;
static uint8_t *t2_buf;
static uint8_t *s_buf;
static size_t data_size;

void init_vars() {
    data_size = 128 * 1024 * 1024;
    half_size = data_size / 2;

    t1_buf = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    t2_buf = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    s_buf = (uint8_t *)malloc(2 * data_size * sizeof(uint8_t));

    if (!t1_buf || !t2_buf || !s_buf) {
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        t1_buf[idx] = (uint8_t)(idx & 0xFF);
        t2_buf[idx] = (uint8_t)((idx + 1) & 0xFF);
    }

    t1 = t1_buf;
    t2 = t2_buf;
    s = s_buf;
}
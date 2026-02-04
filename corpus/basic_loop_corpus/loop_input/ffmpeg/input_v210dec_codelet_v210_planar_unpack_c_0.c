#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *src;
uint16_t *y;
uint16_t *u;
uint16_t *v;
int width;
uint32_t val;
int i;

static uint32_t *src_buf;
static uint16_t *y_buf;
static uint16_t *u_buf;
static uint16_t *v_buf;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024;
    width = (int)(data_size / sizeof(uint32_t));
    width = (width / 6) * 6;

    src_buf = aligned_alloc(32, width * sizeof(uint32_t));
    y_buf = aligned_alloc(32, width * 2 * sizeof(uint16_t));
    u_buf = aligned_alloc(32, width * sizeof(uint16_t));
    v_buf = aligned_alloc(32, width * sizeof(uint16_t));

    for (int j = 0; j < width; j++) {
        src_buf[j] = (uint32_t)(0xABCDU + j);
    }
    for (int j = 0; j < width * 2; j++) {
        y_buf[j] = 0;
    }
    for (int j = 0; j < width; j++) {
        u_buf[j] = 0;
        v_buf[j] = 0;
    }

    src = src_buf;
    y = y_buf;
    u = u_buf;
    v = v_buf;
    val = 0;
    i = 0;
}
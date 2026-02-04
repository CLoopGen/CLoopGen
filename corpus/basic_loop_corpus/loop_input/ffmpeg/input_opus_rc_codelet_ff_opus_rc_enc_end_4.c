#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int lap;
uint8_t *rb_src;
uint8_t *rb_dst;

static uint8_t *internal_rb_src;
static uint8_t *internal_rb_dst;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB

    internal_rb_src = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    internal_rb_dst = (uint8_t *)calloc(data_size, sizeof(uint8_t));

    if (!internal_rb_src || !internal_rb_dst) {
        exit(1);
    }

    rb_src = internal_rb_src;
    rb_dst = internal_rb_dst;
    lap = (int)data_size;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int height;
int width;
int x;
int y;
int8_t *filter;
int16_t *tmp;

static int16_t *dst_buffer;
static int16_t *tmp_buffer;
static int8_t filter_buffer[8];

void init_vars() {
    width = 64;
    height = 4000;

    size_t tmp_size = (height + 7) * 64 * sizeof(int16_t);
    tmp_buffer = (int16_t*)calloc(1, tmp_size);
    if (!tmp_buffer) exit(1);

    dst_buffer = (int16_t*)calloc(1, height * width * sizeof(int16_t));
    if (!dst_buffer) exit(1);

    filter = filter_buffer;
    tmp = tmp_buffer + 3 * 64;
    dst = dst_buffer;

    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    for (int i = 0; i < (height + 7) * 64; i++) {
        tmp_buffer[i] = (int16_t)(i % 512);
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *dst;
char *s;
int i;

static uint8_t *dst_buffer;
static char *s_buffer;
static size_t data_size = 128 * 1024 * 1024; // 128 MB

void init_vars() {
    dst_buffer = (uint8_t*)aligned_alloc(32, data_size * 3);
    s_buffer = (char*)aligned_alloc(32, data_size + 1);

    if (!dst_buffer || !s_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        s_buffer[idx] = (char)(32 + (idx % 95));
    }
    s_buffer[data_size] = '\0';

    dst = dst_buffer;
    s = s_buffer;
    i = 0;
}
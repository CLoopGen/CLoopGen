#include <stdint.h>
#include <stdlib.h>

uint16_t *dst;
unsigned int dst_width;
unsigned int dst_height;
int i;
int j;
uint16_t *last_line;

void init_vars() {
    dst_width = 1024;
    dst_height = 512;
    size_t total_size = (size_t)dst_width * dst_height * sizeof(uint16_t);

    dst = aligned_alloc(32, total_size);
    last_line = aligned_alloc(32, dst_width * sizeof(uint16_t));

    i = 0;
    j = 0;

    for (unsigned int idx = 0; idx < dst_width; ++idx) {
        last_line[idx] = (uint16_t)(idx & 0xFFFF);
    }

    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); ++idx) {
        ((uint16_t *)dst)[idx] = 0;
    }
}
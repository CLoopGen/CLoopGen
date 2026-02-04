#include <stdint.h>
#include <stdlib.h>

int x;
int w = 131072;  // 128K elements to target ~0.01 sec runtime
int my = 15;
int avg = 1;

uint16_t *tmp_ptr;
uint16_t *dst;

void init_vars() {
    size_t total_size = w + 64;
    tmp_ptr = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));

    for (int i = 0; i < w; i++) {
        dst[i] = (uint16_t)(i & 0xFFFF);
        tmp_ptr[i] = (uint16_t)((i * 3) & 0xFFFF);
    }
    for (int i = w; i < w + 64; i++) {
        tmp_ptr[i] = (uint16_t)((i * 7) & 0xFFFF);
    }
}
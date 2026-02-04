#include <stdlib.h>
#include <stdint.h>

int w;
uint32_t *src;
uint32_t *dst;
int j;

void init_vars() {
    w = 65536; // Size to achieve ~0.01 sec runtime on modern CPU

    src = (uint32_t*)aligned_alloc(32, sizeof(uint32_t) * (w + 1));
    dst = (uint32_t*)aligned_alloc(32, sizeof(uint32_t) * w);

    for (int i = 0; i <= w; i++) {
        src[i] = (uint32_t)(i * 31);
    }
}
#include <stdlib.h>
#include <stdint.h>

uint8_t *src;
uint8_t *dst;
int src_size;
unsigned int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    src_size = (data_size / 3) * 3; // Ensure divisible by 3 to satisfy loop increment and bounds

    src = (uint8_t *)malloc(src_size);
    dst = (uint8_t *)malloc(src_size);

    for (int j = 0; j < src_size; ++j) {
        src[j] = (uint8_t)(j & 0xFF);
    }
}

void loop();
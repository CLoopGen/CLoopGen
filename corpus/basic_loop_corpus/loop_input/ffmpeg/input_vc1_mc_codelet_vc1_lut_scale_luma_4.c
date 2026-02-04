#include <stdint.h>
#include <stdlib.h>

uint8_t *srcY;
uint8_t *lut1;
uint8_t *lut2;
int k;
int linesize;
int i;
int j;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *buffer;

void init_vars() {
    k = 4096;
    linesize = k;
    buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    srcY = buffer;
    lut1 = (uint8_t*)aligned_alloc(32, 256);
    lut2 = (uint8_t*)aligned_alloc(32, 256);

    for (int idx = 0; idx < 256; idx++) {
        lut1[idx] = (uint8_t)((idx * 7) % 256);
        lut2[idx] = (uint8_t)((idx * 13 + 5) % 256);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        buffer[idx] = (uint8_t)(idx % 256);
    }
}
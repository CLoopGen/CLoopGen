#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int dst_step;
uint8_t *src;
int src_step;
int len;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

void init_vars() {
    len = DATA_SIZE;
    dst_step = 1;
    src_step = 1;

    src = (uint8_t*)malloc(DATA_SIZE);
    dst = (uint8_t*)malloc(DATA_SIZE);

    if (!src || !dst) {
        exit(1);
    }

    for (int j = 0; j < DATA_SIZE; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }
}
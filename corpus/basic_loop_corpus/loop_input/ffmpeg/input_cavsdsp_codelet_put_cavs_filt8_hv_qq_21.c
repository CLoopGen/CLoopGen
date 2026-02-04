#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define TMP_SIZE (20 * 8)
#define DST_HEIGHT 8
#define DATA_SIZE_MB 64

static uint8_t internal_cm[1024];
static int16_t internal_tmp[TMP_SIZE];
static uint8_t internal_dst_buffer[DATA_SIZE_MB * 1024 * 1024 / 8];

void init_vars() {
    const size_t total_elements = (DATA_SIZE_MB * 1024ULL * 1024) / sizeof(int16_t);
    w = total_elements > INT32_MAX ? INT32_MAX : (int)total_elements;
    
    if (w > (TMP_SIZE - 10) * 8) {
        w = (TMP_SIZE - 10) * 8;
    }

    for (int j = 0; j < 1024; j++) {
        internal_cm[j] = (uint8_t)((j * 97) % 256);
    }

    for (int j = 0; j < TMP_SIZE; j++) {
        internal_tmp[j] = (int16_t)((rand() % 2048) - 1024);
    }

    dstStride = 1;
    dst = internal_dst_buffer;
    tmp = internal_tmp + 2 * 8;
    cm = internal_cm;
    i = 0;
}
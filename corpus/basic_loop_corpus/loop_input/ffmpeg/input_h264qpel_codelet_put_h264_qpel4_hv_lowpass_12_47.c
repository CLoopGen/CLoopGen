#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

#define DATA_SIZE (64 * 1024 * 1024)
#define SRC_WIDTH 8
#define TMP_WIDTH 4

static int32_t *tmp_buffer;
static uint16_t *src_buffer;

void init_vars() {
    const int alignment = 64;
    h = 16384;
    pad = 10;
    srcStride = SRC_WIDTH;
    tmpStride = TMP_WIDTH;

    posix_memalign((void**)&src_buffer, alignment, DATA_SIZE);
    posix_memalign((void**)&tmp_buffer, alignment, DATA_SIZE);

    src = src_buffer;
    tmp = tmp_buffer;

    for (size_t i = 0; i < DATA_SIZE / sizeof(uint16_t); i++) {
        src_buffer[i] = rand() % 1024;
    }

    for (size_t i = 0; i < DATA_SIZE / sizeof(int32_t); i++) {
        tmp_buffer[i] = 0;
    }
}
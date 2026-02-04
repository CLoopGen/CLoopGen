#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define TMP_SIZE (12 * 8)
#define DST_HEIGHT 8
#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(int16_t))
#define W_VALUE (TOTAL_ELEMENTS / 8)

static uint8_t internal_cm[256];
static int16_t *internal_tmp;
static uint8_t *internal_dst;

void init_vars() {
    w = W_VALUE;

    dstStride = 1;

    internal_tmp = aligned_alloc(32, (TMP_SIZE + w) * sizeof(int16_t));
    if (!internal_tmp) exit(1);
    for (int j = 0; j < TMP_SIZE + w; j++) {
        internal_tmp[j] = rand() % 256 - 128;
    }
    tmp = internal_tmp + 2 * 8;

    internal_dst = aligned_alloc(32, w * DST_HEIGHT * sizeof(uint8_t));
    if (!internal_dst) exit(1);
    dst = internal_dst;

    for (int j = 0; j < 256; j++) {
        internal_cm[j] = rand() % 256;
    }
    cm = internal_cm;
}
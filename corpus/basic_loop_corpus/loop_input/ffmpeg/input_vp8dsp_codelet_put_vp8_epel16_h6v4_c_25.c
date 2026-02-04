#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DST_TOTAL_SIZE (256 * 1024 * 1024)
#define TMP_TOTAL_SIZE (DST_TOTAL_SIZE + 3 * 16)

static uint8_t internal_dst[DST_TOTAL_SIZE];
static uint8_t internal_tmp[TMP_TOTAL_SIZE];
static uint8_t internal_filter[5];
static uint8_t internal_cm[256];

uint8_t *dst = internal_dst;
ptrdiff_t dststride = 16;
int h = DST_TOTAL_SIZE / 16;
uint8_t *filter = internal_filter;
uint8_t *cm = internal_cm;
int x;
int y;
uint8_t *tmp = internal_tmp;

void init_vars() {
    for (int i = 0; i < 5; i++) {
        internal_filter[i] = (i == 0) ? 0 : (i * 17);
    }
    for (int i = 0; i < 256; i++) {
        internal_cm[i] = (uint8_t)i;
    }
    for (int i = 0; i < TMP_TOTAL_SIZE; i++) {
        internal_tmp[i] = (uint8_t)(i % 256);
    }
    for (int i = 0; i < DST_TOTAL_SIZE; i++) {
        internal_dst[i] = 0;
    }
}
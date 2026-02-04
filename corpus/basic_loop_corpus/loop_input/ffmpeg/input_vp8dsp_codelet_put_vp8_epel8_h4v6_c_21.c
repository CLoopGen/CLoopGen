#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dststride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define TMP_SIZE (1 << 20)  // ~1MB of data for tmp
#define DST_SIZE (h * dststride)
#define CM_SIZE (256)

static uint8_t *internal_dst_storage;
static uint8_t *internal_tmp_storage;
static uint8_t internal_filter[6] = {8, 12, 16, 16, 12, 8};
static uint8_t internal_cm[CM_SIZE];

void init_vars() {
    h = 4096;
    dststride = 16;

    internal_dst_storage = aligned_alloc(32, DST_SIZE);
    dst = internal_dst_storage;

    internal_tmp_storage = aligned_alloc(32, TMP_SIZE);
    tmp = internal_tmp_storage;

    filter = internal_filter;
    cm = internal_cm;

    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = (uint8_t)i;
    }

    for (int i = 0; i < TMP_SIZE; i++) {
        internal_tmp_storage[i] = rand() & 0xFF;
    }

    for (int i = 0; i < DST_SIZE; i++) {
        internal_dst_storage[i] = 0;
    }
}
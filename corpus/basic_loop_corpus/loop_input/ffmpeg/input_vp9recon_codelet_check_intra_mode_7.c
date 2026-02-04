#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *l;
int bytesperpixel;
int n_px_need;
int i;
int n_px_have;
uint8_t *dst;
ptrdiff_t stride;

static uint8_t *l_storage;
static uint8_t *dst_storage;

void init_vars() {
    bytesperpixel = 2;
    n_px_need = 1 << 20;
    n_px_have = 1 << 20;
    stride = 2;

    l_storage = aligned_alloc(32, (size_t)n_px_need * 2);
    dst_storage = aligned_alloc(32, (size_t)n_px_have * 2 + 2);

    l = l_storage;
    dst = dst_storage + 2;

    for (int i = 0; i < n_px_have * 2; ++i) {
        dst_storage[i] = rand() & 0xFF;
    }
    for (int i = 0; i < n_px_need * 2; ++i) {
        l_storage[i] = 0;
    }
}
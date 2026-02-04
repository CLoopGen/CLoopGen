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
int i;
int n_px_have;
uint8_t *dst;
ptrdiff_t stride;

#define DATA_SIZE (1 << 20)  // 1MB of data for ~0.01 sec runtime estimate

static uint8_t *l_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    bytesperpixel = 2;  // choose 2 to exercise the av_alias16 branch
    n_px_have = DATA_SIZE / (bytesperpixel * 2);  // ensure we have enough pixels
    stride = bytesperpixel;

    l_buffer = aligned_alloc(16, n_px_have * bytesperpixel);
    dst_buffer = aligned_alloc(16, n_px_have * bytesperpixel + stride);

    l = l_buffer;
    dst = dst_buffer + stride;  // offset dst so that dst[-stride] is valid

    for (i = 0; i < n_px_have * bytesperpixel; i++) {
        dst_buffer[i + stride] = rand() & 0xFF;
    }
    for (i = 0; i < n_px_have * bytesperpixel; i++) {
        l_buffer[i] = 0;
    }
}
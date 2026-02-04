#include <stdint.h>
#include <stdlib.h>

void *dst;
int stride;
int bits;
int i;
int x;
int Ra;
int r;

static uint8_t *data_8;
static uint16_t *data_16;

void init_vars() {
    const size_t data_size = 128 << 20; // 128 MB
    bits = rand() % 2 ? 8 : 16;
    stride = (bits == 8) ? 1 : 2;
    Ra = rand();
    r = (bits == 8) ? data_size / 1 : data_size / 2;
    x = 0;

    if (bits == 8) {
        data_8 = aligned_alloc(64, data_size);
        dst = data_8;
    } else {
        data_16 = aligned_alloc(64, data_size);
        dst = data_16;
    }
}
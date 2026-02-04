#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = 1024;
ptrdiff_t stride = 512;
uint16_t *src;
uint16_t *left;
int bottom_left_size = 65536;

static uint16_t src_buf[134217728]; // ~256MB buffer to ensure sufficient data
static uint16_t left_buf[134218752]; // Slightly larger to accommodate index range

void init_vars() {
    src = src_buf;
    left = left_buf;
    size = 1024;
    stride = 512;
    bottom_left_size = 65536;

    for (int idx = 0; idx < 134217728; ++idx) {
        src_buf[idx] = (uint16_t)(idx & 0xFFFF);
    }
    for (int idx = 0; idx < 134218752; ++idx) {
        left_buf[idx] = 0;
    }
}
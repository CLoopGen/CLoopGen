#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int stride;
int i;
int tblk[16];

static uint8_t dst_buffer[256 * 1024 * 1024]; // 256 MB buffer

void init_vars() {
    stride = 4;
    dst = dst_buffer;
    for (int idx = 0; idx < 16; idx++) {
        tblk[idx] = rand() % 1000;
    }
}
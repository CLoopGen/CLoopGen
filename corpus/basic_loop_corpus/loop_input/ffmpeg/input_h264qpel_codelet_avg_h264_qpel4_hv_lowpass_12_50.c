#include <stdlib.h>
#include <stdint.h>

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    h = 10000;
    pad = 10;
    srcStride = 8;
    tmpStride = 4;

    size_t src_size = (h + 5) * srcStride * sizeof(uint16_t);
    size_t tmp_size = (h + 5) * tmpStride * sizeof(int32_t);

    src = aligned_alloc(32, src_size);
    tmp = aligned_alloc(32, tmp_size);

    for (int idx = 0; idx < (h + 5) * srcStride; idx++) {
        src[idx] = (uint16_t)(idx % 1024);
    }
    for (int idx = 0; idx < (h + 5) * tmpStride; idx++) {
        tmp[idx] = 0;
    }
}
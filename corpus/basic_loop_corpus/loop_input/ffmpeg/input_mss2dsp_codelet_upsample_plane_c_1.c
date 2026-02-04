#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int w;
uint8_t *src1;
uint8_t *src2;
uint8_t *dst1;
uint8_t *dst2;
uint8_t a;
uint8_t b;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    w = (int)data_size;

    src1 = aligned_alloc(32, data_size);
    src2 = aligned_alloc(32, data_size);
    dst1 = aligned_alloc(32, data_size);
    dst2 = aligned_alloc(32, data_size);

    for (size_t idx = 0; idx < data_size; idx++) {
        src1[idx] = rand() & 0xFF;
        src2[idx] = rand() & 0xFF;
    }

    memset(dst1, 0, data_size);
    memset(dst2, 0, data_size);
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TMP_HEIGHT (DATA_SIZE_MB * 1024 * 1024 / 16)
#define H_VALUE (TMP_HEIGHT - 3)

uint8_t *dst;
ptrdiff_t dststride;
int h = H_VALUE;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

void init_vars() {
    const int filter_size = 5;
    const int cm_size = 256;
    const int tmp_width = 16;
    const int total_tmp_size = tmp_width * TMP_HEIGHT;

    dststride = 16;

    filter = aligned_alloc(32, filter_size * sizeof(uint8_t));
    cm = aligned_alloc(32, cm_size * sizeof(uint8_t));
    tmp = aligned_alloc(32, total_tmp_size * sizeof(uint8_t));
    dst = aligned_alloc(32, (size_t)dststride * h);

    for (int i = 0; i < filter_size; i++)
        filter[i] = (uint8_t)(i * 17 + 3);
    for (int i = 0; i < cm_size; i++)
        cm[i] = (uint8_t)i;
    for (int i = 0; i < total_tmp_size; i++)
        tmp[i] = (uint8_t)(i % 251);
}
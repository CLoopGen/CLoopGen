#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(uint16_t)
#define NUM_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

static int32_t *tmp_data;
static uint16_t *src_data;

void init_vars() {
    h = 10000;
    pad = 10;
    srcStride = 1;
    tmpStride = 2;

    tmp_data = (int32_t*)aligned_alloc(32, (h + 5) * tmpStride * sizeof(int32_t));
    src_data = (uint16_t*)aligned_alloc(32, (h + 5) * srcStride * sizeof(uint16_t) + 5);

    if (!tmp_data || !src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    tmp = tmp_data;
    src = src_data + 2;

    for (int idx = 0; idx < (h + 5) * srcStride + 3; idx++) {
        src_data[idx] = (uint16_t)(idx % 300);
    }

    for (int idx = 0; idx < (h + 5) * tmpStride; idx++) {
        tmp_data[idx] = 0;
    }
}
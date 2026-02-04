#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src_data;
int src_linesize;
uint8_t *dst_data;
int dst_linesize;
int src_w;
int src_h;
int x;
int y;

void init_vars() {
    src_w = 1024;
    src_h = 1024;
    src_linesize = src_w;
    dst_linesize = src_w / 2;

    src_data = (uint8_t *)aligned_alloc(32, src_h * src_linesize * sizeof(uint8_t));
    dst_data = (uint8_t *)aligned_alloc(32, (src_h / 2) * dst_linesize * sizeof(uint8_t));

    for (int i = 0; i < src_h * src_linesize; i++) {
        src_data[i] = rand() % 256;
    }
    for (int i = 0; i < (src_h / 2) * dst_linesize; i++) {
        dst_data[i] = 0;
    }
}
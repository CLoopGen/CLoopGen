#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dststride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define TMP_SIZE (1 << 20)
static uint8_t tmp_buffer[TMP_SIZE] __attribute__((aligned(32)));
static uint8_t dst_buffer[TMP_SIZE] __attribute__((aligned(32)));
static uint8_t filter_buffer[5] __attribute__((aligned(32))) = {0, 16, 32, 48, 64};
static uint8_t cm_buffer[256] __attribute__((aligned(32)));

void init_vars() {
    for (int i = 0; i < 256; i++) {
        cm_buffer[i] = (uint8_t)i;
    }

    h = 1024;
    dststride = 16;
    dst = dst_buffer;
    filter = filter_buffer;
    cm = cm_buffer;
    tmp = tmp_buffer;

    for (int i = 0; i < TMP_SIZE; i++) {
        tmp_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = 0;
    }
}
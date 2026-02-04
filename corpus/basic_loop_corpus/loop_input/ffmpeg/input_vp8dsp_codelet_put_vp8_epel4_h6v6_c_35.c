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
#define CM_SIZE (1 << 8)

static uint8_t dst_buffer[65536];
static uint8_t tmp_buffer[TMP_SIZE];
static uint8_t filter_buffer[6] = {1, 2, 4, 8, 16, 32};
static uint8_t cm_buffer[CM_SIZE];

void init_vars() {
    h = 4096;
    dststride = 16;
    
    filter = filter_buffer;
    cm = cm_buffer;
    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    tmp = tmp_buffer;
    dst = dst_buffer;

    for (int i = 0; i < TMP_SIZE; i++) {
        tmp[i] = (uint8_t)(i % 256);
    }
}
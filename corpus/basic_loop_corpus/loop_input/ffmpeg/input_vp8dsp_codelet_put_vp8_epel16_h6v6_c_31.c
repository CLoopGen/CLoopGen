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

#define TMP_SIZE (16 * 256 * 1024)
#define CM_SIZE 256
#define FILTER_SIZE 6

static uint8_t _dst_buffer[16 * 65536];
static uint8_t _tmp_buffer[TMP_SIZE];
static uint8_t _cm_buffer[CM_SIZE];
static uint8_t _filter_buffer[FILTER_SIZE];

void init_vars() {
    h = 65536;
    dststride = 16;

    filter = _filter_buffer;
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 8;
    filter[3] = 8;
    filter[4] = 2;
    filter[5] = 1;

    cm = _cm_buffer;
    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = i;
    }

    tmp = _tmp_buffer;
    for (size_t i = 0; i < TMP_SIZE; i++) {
        tmp[i] = rand() & 0xFF;
    }

    dst = _dst_buffer;
}
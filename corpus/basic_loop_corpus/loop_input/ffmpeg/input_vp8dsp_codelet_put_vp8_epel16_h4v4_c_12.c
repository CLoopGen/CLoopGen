#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define TMP_SIZE (16 * 1024 * 1024 / 16)  // ~16 MB for tmp
#define SRC_HEIGHT (TMP_SIZE / 16)
#define SRC_WIDTH (16 + 3)

static uint8_t internal_src[SRC_HEIGHT * SRC_WIDTH];
static uint8_t internal_tmp[TMP_SIZE];
static uint8_t internal_filter[5] = {0, 8, 16, 8, 4};  // example filter values
static uint8_t internal_cm[512];  // cm table with margin

void init_vars() {
    src = internal_src;
    tmp = internal_tmp;
    filter = internal_filter;
    cm = internal_cm;
    h = SRC_HEIGHT - 4 + 1;  // ensures y < h+4-1 => y < SRC_HEIGHT
    srcstride = SRC_WIDTH;
    x = 0;
    y = 0;

    for (int i = 0; i < 512; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }
}
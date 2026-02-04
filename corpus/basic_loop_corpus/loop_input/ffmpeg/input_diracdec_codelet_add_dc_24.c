#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
int dc;
int stride;
uint8_t *obmc_weight;
int xblen;
int yblen;
int x;
int y;

static uint16_t dst_buffer[1 << 20];
static uint8_t obmc_weight_buffer[32 * (1 << 15)];

void init_vars() {
    xblen = 64;
    yblen = 1024;
    dc = 123;
    stride = 64;
    dst = dst_buffer;
    obmc_weight = obmc_weight_buffer;
    x = 0;
    y = 0;
}
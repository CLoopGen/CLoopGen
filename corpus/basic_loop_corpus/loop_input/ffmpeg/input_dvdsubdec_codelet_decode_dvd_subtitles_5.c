#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int pos;
uint8_t *alpha;
int i;

static uint8_t buf_data[1 << 20]; // 1MB buffer
static uint8_t alpha_data[256];

void init_vars() {
    buf = buf_data;
    alpha = alpha_data;
    pos = 0;
    i = 0;
}
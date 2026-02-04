#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *pal;
int r;
int g;
int b;

static uint32_t pal_buffer[1296]; // 6*6*6 = 1296 elements

void init_vars() {
    pal = pal_buffer;
}
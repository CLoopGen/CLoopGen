#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *pal;
int g;

static uint32_t pal_buffer[256 * 1024 * 1024 / sizeof(uint32_t)]; // ~256MB buffer

void init_vars() {
    pal = pal_buffer;
    g = 0;
}
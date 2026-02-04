#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int i;
int num_pixels;

static uint16_t src_buffer[65536];
static uint16_t dst_buffer[65536];

void init_vars() {
    num_pixels = 65536;
    src = (uint8_t *)src_buffer;
    dst = (uint8_t *)dst_buffer;
    for (int j = 0; j < num_pixels; j++) {
        src_buffer[j] = rand() & 0xFFFF;
    }
}
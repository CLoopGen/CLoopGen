#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int width;
uint8_t *src;
int x;
int mask;
int dsp_mask;
int j;
int src_x;
int b;

static uint8_t dst_buffer[65536];
static uint8_t src_buffer[65536];

void init_vars() {
    width = 65536;
    mask = 0x80;
    dsp_mask = 0x80;
    src_x = 0;

    dst = dst_buffer;
    src = src_buffer;

    for (int i = 0; i < 65536; i++) {
        src_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = rand() & 0xFF;
    }
}
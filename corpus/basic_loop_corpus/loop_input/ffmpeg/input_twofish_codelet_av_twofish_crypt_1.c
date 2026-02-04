#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *iv;
int i;

static uint8_t dst_buffer[16777216]; // 16MB
static uint8_t src_buffer[16777216]; // 16MB
static uint8_t iv_buffer[16777216];  // 16MB

void init_vars() {
    dst = dst_buffer;
    src = src_buffer;
    iv  = iv_buffer;

    for (size_t j = 0; j < sizeof(src_buffer); ++j) {
        src_buffer[j] = (uint8_t)(j & 0xFF);
    }
    for (size_t j = 0; j < sizeof(iv_buffer); ++j) {
        iv_buffer[j] = (uint8_t)((j ^ 0xAA) & 0xFF);
    }
    for (size_t j = 0; j < sizeof(dst_buffer); ++j) {
        dst_buffer[j] = 0;
    }

    i = 0;
}
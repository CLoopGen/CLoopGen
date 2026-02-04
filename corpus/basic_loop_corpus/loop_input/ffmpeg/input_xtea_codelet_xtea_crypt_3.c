#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *iv;
int i;

static uint8_t dst_buffer[262144];
static uint8_t src_buffer[262144];
static uint8_t iv_buffer[262144];

void init_vars() {
    dst = dst_buffer;
    src = src_buffer;
    iv = iv_buffer;

    for (int j = 0; j < 262144; j++) {
        src[j] = rand() & 0xFF;
        iv[j] = rand() & 0xFF;
    }
}
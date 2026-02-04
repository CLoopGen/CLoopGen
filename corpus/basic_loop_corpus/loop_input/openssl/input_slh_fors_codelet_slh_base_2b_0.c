#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t *in;
uint32_t b;
uint32_t *out;
size_t out_len;
size_t consumed;
uint32_t bits;
uint32_t total;
uint32_t mask;

static uint8_t in_buffer[1024 * 1024];
static uint32_t out_buffer[256 * 1024];

void init_vars() {
    b = 5;
    out_len = 200000;
    mask = (1U << b) - 1;
    bits = 0;
    total = 0;
    consumed = 0;

    in = in_buffer;
    out = out_buffer;

    for (size_t i = 0; i < sizeof(in_buffer); i++) {
        in_buffer[i] = rand() & 0xFF;
    }
}
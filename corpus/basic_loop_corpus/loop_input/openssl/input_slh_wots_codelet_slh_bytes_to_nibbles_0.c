#include <stdint.h>
#include <stdlib.h>

uint8_t *in;
size_t in_len;
uint8_t *out;
size_t consumed;

static uint8_t in_buffer[512 * 1024];
static uint8_t out_buffer[1024 * 1024];

void init_vars() {
    in = in_buffer;
    in_len = sizeof(in_buffer);
    out = out_buffer;
}
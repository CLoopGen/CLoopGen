#include <stdint.h>
#include <stddef.h>

uint8_t *in;
size_t in_len;
size_t i;
uint16_t csum;

static uint8_t in_buffer[131072]; // 128 KB

void init_vars() {
    in = in_buffer;
    in_len = sizeof(in_buffer);
    i = 0;
    csum = 0;
}
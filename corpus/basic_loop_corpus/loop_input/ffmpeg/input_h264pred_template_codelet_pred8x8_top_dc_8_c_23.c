#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint8_t *src;

static uint8_t src_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    stride = 4;
    i = 0;
    dc0 = 0;
    dc1 = 0;
    src = src_buffer + stride; // Ensure that src[i - stride] is within bounds for i in [0,3]
}
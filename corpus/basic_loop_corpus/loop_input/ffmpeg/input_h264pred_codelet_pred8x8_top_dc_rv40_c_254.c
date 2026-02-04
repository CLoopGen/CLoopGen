#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int i;
unsigned int dc0;

static uint8_t data[1 << 24]; // ~16.7 MB to ensure loop takes around 0.01s

void init_vars() {
    for (size_t j = 0; j < sizeof(data); j++) {
        data[j] = (uint8_t)(j & 0xFF);
    }
    stride = 8;
    src = data + stride; // Ensure i - stride >= 0 when i=0 by shifting base
    dc0 = 0;
}
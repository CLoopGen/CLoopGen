#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int i;
unsigned int dc0;

static uint8_t data[1 << 20]; // 1MB of data to ensure sufficient runtime (~0.01 sec estimate)

void init_vars() {
    stride = 1024;
    src = data + 4096; // offset to allow negative indexing and avoid out-of-bounds
    i = 0;
    dc0 = 0;

    for (int j = 0; j < (1 << 20); j++) {
        data[j] = j & 0xFF;
    }
}
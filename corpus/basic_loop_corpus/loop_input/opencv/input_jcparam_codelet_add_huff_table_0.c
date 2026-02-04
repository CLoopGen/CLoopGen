#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char UINT8;

UINT8 *bits;
int nsymbols;
int len;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    bits = (UINT8*)calloc(data_size, sizeof(UINT8));
    if (!bits) {
        exit(1);
    }
    for (size_t i = 1; i <= 16; i++) {
        bits[i] = rand() & 0xFF;
    }
    nsymbols = 0;
    len = 0;
}
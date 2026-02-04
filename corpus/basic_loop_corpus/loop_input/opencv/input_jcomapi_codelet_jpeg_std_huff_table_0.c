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
    bits = (UINT8*)malloc(data_size);
    if (!bits) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; i++) {
        bits[i] = (UINT8)(i % 256);
    }
    nsymbols = 0;
    len = 0;
}
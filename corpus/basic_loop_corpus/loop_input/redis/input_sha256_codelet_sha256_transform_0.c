#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint8_t BYTE;
typedef uint32_t WORD;

BYTE data[1 << 20]; // 1MB of data to ensure ~0.01s runtime
WORD i;
WORD j;
WORD m[64];

void init_vars() {
    for (size_t idx = 0; idx < sizeof(data); ++idx) {
        data[idx] = (BYTE)(idx & 0xFF);
    }
    i = 0;
    j = 0;
    for (size_t idx = 0; idx < 64; ++idx) {
        m[idx] = 0;
    }
}
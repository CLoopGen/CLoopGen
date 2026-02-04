#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;

union av_intfloat32 {
    uint32_t i;
    float f;
};

INTFLOAT *buf;
int len;
int bits;
int i;

void init_vars() {
    len = 67108864; // Approximately 256MB of float data (67M elements * 4 bytes)
    bits = 3;       // Arbitrary bit mask value within valid range (0-31)
    buf = (INTFLOAT*)aligned_alloc(32, len * sizeof(INTFLOAT));
    if (!buf) {
        exit(1);
    }
    for (int j = 0; j < len; j++) {
        buf[j] = (INTFLOAT)(j % 1000) / 100.0f;
    }
    i = 0;
}
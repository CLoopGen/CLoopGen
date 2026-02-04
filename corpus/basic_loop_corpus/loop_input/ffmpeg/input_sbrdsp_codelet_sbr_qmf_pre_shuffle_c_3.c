#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union av_intfloat32 {
    uint32_t i;
    float f;
};

union av_intfloat32 *zi;
int k;

static union av_intfloat32 zi_data[256];

void init_vars() {
    zi = zi_data;
    k = 0;
}
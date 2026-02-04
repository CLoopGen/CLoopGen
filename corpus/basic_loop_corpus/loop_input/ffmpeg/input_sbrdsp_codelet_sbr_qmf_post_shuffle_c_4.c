#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union av_intfloat32 {
    uint32_t i;
    float f;
};

union av_intfloat32 *zi;
union av_intfloat32 *Wi;
int k;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * (1 << 20)) / sizeof(union av_intfloat32))

static union av_intfloat32 zi_storage[TOTAL_ELEMENTS];
static union av_intfloat32 Wi_storage[TOTAL_ELEMENTS];

void init_vars() {
    zi = zi_storage;
    Wi = Wi_storage;
    k = 0;

    for (size_t i = 0; i < TOTAL_ELEMENTS; ++i) {
        zi_storage[i].i = (uint32_t)(0xDEADBEEF ^ i);
        Wi_storage[i].i = 0;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int length;
int16_t *destPtr;
int16_t *sourcePtr;
int j;

static int16_t *sourceArray;
static int16_t *destArray;

void init_vars() {
    const size_t dataSize = 64 * 1024 * 1024; // ~128 MB of data (64M int16_t elements)
    length = dataSize / sizeof(int16_t);

    sourceArray = aligned_alloc(32, dataSize);
    destArray = aligned_alloc(32, dataSize);

    if (!sourceArray || !destArray) {
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        sourceArray[i] = (int16_t)(i & 0xFFFF);
    }

    destPtr = &destArray[length - 1];
    sourcePtr = sourceArray;
}
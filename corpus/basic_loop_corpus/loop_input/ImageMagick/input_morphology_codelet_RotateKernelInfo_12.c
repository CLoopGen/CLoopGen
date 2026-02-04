#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

MagickRealType t;
ssize_t i;
ssize_t j;
MagickRealType *k;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 2^20 bytes
    j = (data_size / sizeof(MagickRealType)) - 1; // number of elements - 1

    k = aligned_alloc(32, data_size);
    if (!k) {
        exit(1);
    }

    for (size_t idx = 0; idx <= (size_t)j; idx++) {
        k[idx] = (MagickRealType)(idx + 1);
    }
}
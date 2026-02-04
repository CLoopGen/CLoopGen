#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char U8;
typedef int I32;

U8 *tmps;
I32 anum;

static U8 *tmps_storage;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    tmps_storage = (U8 *)calloc(data_size, sizeof(U8));
    if (!tmps_storage) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        tmps_storage[i] = (U8)(i & 0xFF);
    }

    tmps = tmps_storage;
    anum = (I32)data_size;
}
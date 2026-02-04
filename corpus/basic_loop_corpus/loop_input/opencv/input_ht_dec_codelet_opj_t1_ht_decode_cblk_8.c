#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

OPJ_UINT32 *decoded_data;
OPJ_INT32 width;
OPJ_INT32 height;
OPJ_INT32 stride;
OPJ_INT32 x;
OPJ_INT32 y;

void init_vars() {
    width = 8192;
    height = 8192;
    stride = width;
    OPJ_UINT32 data_size = height * stride;
    decoded_data = (OPJ_UINT32*)calloc(data_size, sizeof(OPJ_UINT32));
    if (!decoded_data) {
        exit(1);
    }
    for (OPJ_UINT32 i = 0; i < data_size; ++i) {
        decoded_data[i] = rand() % 2 ? 0x80000000U | (rand() & 0x7FFFFFFF) : rand() & 0x7FFFFFFF;
    }
}
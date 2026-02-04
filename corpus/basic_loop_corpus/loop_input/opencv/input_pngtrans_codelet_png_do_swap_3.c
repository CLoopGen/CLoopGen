#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep rp;
png_uint_32 i;
png_uint_32 istop;

static png_byte *data_buffer;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime
    data_buffer = (png_byte*)aligned_alloc(32, data_size);
    if (!data_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data_buffer[idx] = (png_byte)(idx & 0xFF);
    }

    rp = data_buffer;
    istop = data_size / 2;
}
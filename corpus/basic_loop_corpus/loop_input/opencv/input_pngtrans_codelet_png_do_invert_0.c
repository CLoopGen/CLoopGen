#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_bytep rp;
size_t i;
size_t istop;

static png_byte *data_buffer;

void init_vars() {
    const size_t data_size = 128 << 20; // 128 MB
    data_buffer = (png_byte*)calloc(data_size, sizeof(png_byte));
    if (!data_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        data_buffer[idx] = (png_byte)(idx & 0xFF);
    }

    rp = data_buffer;
    i = 0;
    istop = data_size;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

size_t i;
size_t istop;
unsigned int bpp;
png_bytep rp;

static png_byte *data_buffer = NULL;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    bpp = 4; // typical bytes per pixel value

    data_buffer = (png_byte*)calloc(data_size, sizeof(png_byte));
    if (!data_buffer) {
        exit(1);
    }

    // Initialize data with non-zero values to make transformation observable
    for (size_t idx = 0; idx < data_size; idx++) {
        data_buffer[idx] = (png_byte)(idx & 255);
    }

    rp = data_buffer + bpp; // point to first modifiable element
    istop = data_size - bpp; // ensure *(rp - bpp) is valid throughout loop
}

void cleanup_vars() {
    free(data_buffer);
    data_buffer = NULL;
}
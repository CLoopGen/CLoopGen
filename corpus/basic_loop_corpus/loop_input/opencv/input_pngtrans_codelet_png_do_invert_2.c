#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_bytep rp;
size_t i;
size_t istop;

static png_byte *data_buffer;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime on modern CPU
    data_buffer = (png_byte*)aligned_alloc(32, data_size);
    if (!data_buffer) {
        exit(1);
    }
    memset(data_buffer, 0x55, data_size);

    rp = data_buffer;
    istop = data_size - (data_size % 4); // Ensure multiple of 4 to avoid out-of-bounds
}
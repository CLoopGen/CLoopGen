#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_bytep buffer;
png_bytep buf;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB for ~0.01 sec runtime
    buffer = (png_bytep)aligned_alloc(32, data_size);
    if (!buffer) {
        exit(1);
    }
    for (size_t i = 0; i < data_size - 1; i++) {
        buffer[i] = 1;
    }
    buffer[data_size - 1] = 0; // null terminator to stop the loop
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}
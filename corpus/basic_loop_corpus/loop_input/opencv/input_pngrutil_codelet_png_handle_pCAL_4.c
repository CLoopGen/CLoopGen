#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_bytep buf;
png_bytep units;

static png_byte *units_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    units_storage = (png_byte*)calloc(data_size, sizeof(png_byte));
    if (!units_storage) {
        exit(1);
    }
    // Fill with non-zero bytes except last one to simulate string-like termination
    memset(units_storage, 1, data_size - 1);
    units_storage[data_size - 1] = 0; // null terminator
    units = units_storage;
    buf = NULL;
}

__attribute__((destructor)) void cleanup() {
    free(units_storage);
}
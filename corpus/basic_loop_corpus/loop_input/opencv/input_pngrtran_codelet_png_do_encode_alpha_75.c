#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep row;
png_uint_32 row_width;
png_bytep table;
int step;

static png_byte *row_data = NULL;
static png_byte table_data[256];

void init_vars() {
    const size_t data_size = 16777216; // 16 MB for ~0.01 sec runtime on modern CPU

    row_data = (png_byte*)aligned_alloc(32, data_size);
    if (!row_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        row_data[i] = rand() % 256;
    }

    for (int i = 0; i < 256; ++i) {
        table_data[i] = (png_byte)((i * 17 + 251) % 256);
    }

    row = row_data;
    row_width = data_size;
    table = table_data;
    step = 1;
}
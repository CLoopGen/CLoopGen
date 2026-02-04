#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;
typedef unsigned short png_uint_16;
typedef png_uint_16 **png_uint_16pp;

png_bytep row;
png_uint_32 row_width;
png_uint_16pp table;
int gamma_shift;
int step;

static png_byte *row_data = NULL;
static png_uint_16 **table_data = NULL;
static size_t table_size = 256;

void init_vars() {
    gamma_shift = 4;
    step = 2;

    size_t data_size = 16 << 20;
    row_data = (png_byte*)calloc(data_size, sizeof(png_byte));
    if (!row_data) exit(1);

    row = row_data;
    row_width = data_size / step;

    table_data = (png_uint_16**)calloc(table_size, sizeof(png_uint_16*));
    if (!table_data) exit(1);

    for (size_t i = 0; i < table_size; ++i) {
        table_data[i] = (png_uint_16*)malloc(table_size * sizeof(png_uint_16));
        if (!table_data[i]) exit(1);
        for (size_t j = 0; j < table_size; ++j) {
            table_data[i][j] = (png_uint_16)((i * 31 + j * 7) & 0xFFFF);
        }
    }

    table = table_data;
}
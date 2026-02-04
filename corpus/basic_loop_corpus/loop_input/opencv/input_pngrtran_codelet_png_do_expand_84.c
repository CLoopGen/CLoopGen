#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

int shift = 4;
int value;
png_bytep sp;
png_bytep dp;
png_uint_32 i;
png_uint_32 row_width;

#define DATA_SIZE (128 << 20)  // 128 MB

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    sp_buffer = (png_byte*)malloc(DATA_SIZE);
    dp_buffer = (png_byte*)malloc(DATA_SIZE);

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < DATA_SIZE; j++) {
        sp_buffer[j] = (png_byte)(j & 0xFF);
        dp_buffer[j] = 0;
    }

    sp = sp_buffer + DATA_SIZE - 1;
    dp = dp_buffer + DATA_SIZE - 1;
    row_width = DATA_SIZE;
    shift = 4;
}
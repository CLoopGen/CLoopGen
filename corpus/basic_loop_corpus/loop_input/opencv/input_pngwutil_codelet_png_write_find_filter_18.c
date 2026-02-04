#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_bytep row_buf = NULL;
size_t row_bytes = 0;
png_bytep rp = NULL;
size_t sum = 0;
size_t i = 0;
unsigned int v = 0;

void init_vars() {
    row_bytes = 64 * 1024 * 1024;  // 64 MB to target ~0.01 sec on modern CPUs
    row_buf = (png_bytep)aligned_alloc(32, row_bytes);
    if (!row_buf) {
        exit(1);
    }
    for (size_t idx = 0; idx < row_bytes; idx++) {
        row_buf[idx] = (png_byte)(idx % 256);
    }
    rp = row_buf + 1;
    sum = 0;
    i = 0;
    v = 0;
}
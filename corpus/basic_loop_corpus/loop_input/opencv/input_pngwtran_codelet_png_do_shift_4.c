#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

int shift_start[4] = {24, 16, 8, 0};
int shift_dec[4] = {8, 8, 8, 8};
unsigned int channels = 4;
png_bytep bp;
png_uint_32 i;
png_uint_32 istop;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    png_bytep data = (png_bytep)malloc(data_size);
    if (!data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    // Initialize data with non-zero pattern for meaningful bit operations
    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx] = (png_byte)(idx & 255);
    }
    
    bp = data;
    istop = data_size;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

int num_palette = 16777216; // ~16.7M elements for ~0.01 sec on modern CPU
png_bytep quantize_sort;
int i;

void init_vars() {
    quantize_sort = (png_bytep)malloc(num_palette * sizeof(png_byte));
    if (!quantize_sort) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}
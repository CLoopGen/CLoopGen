#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;

typedef struct png_color_struct {
    png_byte red;
    png_byte green;
    png_byte blue;
} png_color;

typedef png_color *png_colorp;
typedef png_byte *png_bytep;

png_colorp palette;
int maximum_colors;
png_bytep quantize_sort;
int i;
int j;

void init_vars() {
    maximum_colors = 1 << 20; // Approximately 1MB of color data (1M entries)

    palette = calloc(maximum_colors, sizeof(png_color));
    quantize_sort = malloc(maximum_colors * sizeof(png_byte));

    if (!palette || !quantize_sort) {
        exit(1);
    }

    for (int idx = 0; idx < maximum_colors; idx++) {
        palette[idx].red = (png_byte)(idx % 256);
        palette[idx].green = (png_byte)((idx + 32) % 256);
        palette[idx].blue = (png_byte)((idx + 64) % 256);
        quantize_sort[idx] = (png_byte)((idx % 260) - 5); // Ensures some values >= maximum_colors when cast to int
    }

    j = maximum_colors - 1;
}
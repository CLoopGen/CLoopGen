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

png_colorp palette;
int num_palette;
int color_inc;
int i;
int v;

void init_vars() {
    num_palette = 65536;
    color_inc = 100;
    palette = (png_colorp)malloc(num_palette * sizeof(png_color));
}

__attribute__((destructor))
void cleanup() {
    free((void*)palette);
}
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

unsigned int num = 256;
unsigned int i;
unsigned int j;
png_byte buf[768];
png_color palette[256];

void init_vars() {
    for (unsigned int idx = 0; idx < 768; ++idx) {
        buf[idx] = (png_byte)(idx % 256);
    }
    for (unsigned int idx = 0; idx < 256; ++idx) {
        palette[idx].red = 0;
        palette[idx].green = 0;
        palette[idx].blue = 0;
    }
    i = 0;
    j = 0;
}
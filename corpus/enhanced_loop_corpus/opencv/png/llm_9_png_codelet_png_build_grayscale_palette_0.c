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

extern png_colorp palette;
extern int num_palette;
extern int color_inc;
extern int i;
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = color_inc + 1;
    for (i = 0; i < num_palette; i += 2, v += step) {
        palette[i].red = (png_byte)(v & 255);
        if (i + 1 < num_palette) {
            palette[i + 1].red = (png_byte)((v + 1) & 255);
            palette[i + 1].green = (png_byte)((v + 1) & 255);
            palette[i + 1].blue = (png_byte)((v + 1) & 255);
        }
        palette[i].green = (png_byte)(v & 255);
        palette[i].blue = (png_byte)(v & 255);
    }
}

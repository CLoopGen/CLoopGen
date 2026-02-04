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
    for (i = 0, v = 0; i < num_palette; i++, v += color_inc) {
        if (v % 2 == 0) {
            palette[i].red = (png_byte)(v & 255);
            palette[i].green = (png_byte)(v & 255);
            palette[i].blue = (png_byte)(v & 255);
        } else {
            palette[i].red = (png_byte)((v + 10) & 255);
            palette[i].green = (png_byte)((v + 20) & 255);
            palette[i].blue = (png_byte)((v + 30) & 255);
        }
    }
}

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
    int temp_red, temp_green, temp_blue;
    for (i = 0, v = 0; i < num_palette; i++, v += color_inc) {
        temp_red = v & 255;
        temp_green = temp_red;  
        temp_blue = temp_red;   
        palette[i].red = (png_byte)temp_red;
        palette[i].green = (png_byte)temp_green;
        palette[i].blue = (png_byte)temp_blue;
    }
}

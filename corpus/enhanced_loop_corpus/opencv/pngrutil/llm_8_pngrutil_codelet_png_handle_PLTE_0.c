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

extern  unsigned int num;
extern unsigned int i;
extern unsigned int j;
extern png_byte buf[768];
extern png_color palette[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0U; i < num; i++) {
        unsigned int base = i * 3;
        palette[i].red = buf[base + 0];
        palette[i].green = buf[base + 1];
        palette[i].blue = buf[base + 2];
    }
}

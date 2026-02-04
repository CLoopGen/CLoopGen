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
    png_byte *b = buf;
    png_color *p = palette;
    for (i = 0U; i < num; i++, p++, b += 3) {
        p->red   = b[0];
        p->green = b[1];
        p->blue  = b[2];
    }
}

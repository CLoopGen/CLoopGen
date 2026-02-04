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
        j = i * 3U;
        palette[i].red   = buf[j + 0U];
        palette[i].green = buf[j + 1U];
        palette[i].blue  = buf[j + 2U];
    }
}

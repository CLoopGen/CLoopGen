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
for (i = 0U, j = 0U; i < num; i++) {
    palette[i].red = buf[j];
    j++;
    if (j % 2 == 0) {
        palette[i].green = buf[j];
        j++;
        palette[i].blue = buf[j];
        j++;
    } else {
        palette[i].green = 0;
        palette[i].blue = 0;
        j += 2;
    }
}
}

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
        for (j = i * 3U; j < i * 3U + 3U; j++) {
            if (j % 3U == 0U) palette[i].red   = buf[j];
            if (j % 3U == 1U) palette[i].green = buf[j];
            if (j % 3U == 2U) palette[i].blue  = buf[j];
        }
    }
}

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned short sixel_pixel_t;

int background_color_index;
int i;
int imsx;
int imsy;
sixel_pixel_t *imbuf;

void init_vars() {
    background_color_index = 0;
    imsx = 1024;
    imsy = 1024;
    size_t total_size = (size_t)imsx * imsy;
    imbuf = (sixel_pixel_t *)calloc(total_size, sizeof(sixel_pixel_t));
    if (!imbuf) {
        exit(1);
    }
}
#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _DIBInfo {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int x_pixels;
    unsigned int y_pixels;
    unsigned int number_colors;
    unsigned int colors_important;
    unsigned short red_mask;
    unsigned short green_mask;
    unsigned short blue_mask;
    unsigned short alpha_mask;
    int colorspace;
    PointInfo red_primary;
    PointInfo green_primary;
    PointInfo blue_primary;
    PointInfo gamma_scale;
} DIBInfo;

extern DIBInfo dib_info;
extern ssize_t i;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t limit = (ssize_t)1 << dib_info.bits_per_pixel;
    for (; i < limit; i++) {
        unsigned char val = (unsigned char)0;
        *q = val;
        *(q + 1) = val;
        *(q + 2) = val;
        *(q + 3) = val;
        q += 4;
    }
}

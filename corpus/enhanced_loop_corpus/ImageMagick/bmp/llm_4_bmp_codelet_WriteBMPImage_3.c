#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PrimaryInfo {
    double x;
    double y;
    double z;
} PrimaryInfo;

typedef struct _BMPInfo {
    unsigned int file_size;
    unsigned int ba_offset;
    unsigned int offset_bits;
    unsigned int size;
    ssize_t width;
    ssize_t height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int x_pixels;
    unsigned int y_pixels;
    unsigned int number_colors;
    unsigned int red_mask;
    unsigned int green_mask;
    unsigned int blue_mask;
    unsigned int alpha_mask;
    unsigned int colors_important;
    long colorspace;
    PrimaryInfo red_primary;
    PrimaryInfo green_primary;
    PrimaryInfo blue_primary;
    PrimaryInfo gamma_scale;
} BMPInfo;

extern BMPInfo bmp_info;
extern size_t type;
extern ssize_t i;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < (ssize_t)1UL << bmp_info.bits_per_pixel; i++) {
        *q++ = (unsigned char)0;
        *q++ = (unsigned char)0;
        *q++ = (unsigned char)0;
        if (type > 2 && i % 2 == 0)
            *q++ = (unsigned char)0;
    }
}

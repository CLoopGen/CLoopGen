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
    // Variant 1: Consecutive memory access using array indexing instead of pointer arithmetic
    unsigned char *base_q = q;
    for (; i < (ssize_t)1L << dib_info.bits_per_pixel; i++) {
        ssize_t idx = i * 4;
        base_q[idx]     = (unsigned char)0;
        base_q[idx + 1] = (unsigned char)0;
        base_q[idx + 2] = (unsigned char)0;
        base_q[idx + 3] = (unsigned char)0;
    }
    q = base_q + (i * 4); // Update q to reflect advancement
}

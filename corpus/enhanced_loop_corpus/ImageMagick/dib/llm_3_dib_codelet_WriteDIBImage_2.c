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
    // Variant 2: Strided memory access - write one component at a time across multiple pixels (SIMD-like pattern)
    // Assumes that bits_per_pixel defines number of entries, and we initialize all R, then all G, etc.
    unsigned char *base_q = q;
    ssize_t total_pixels = (ssize_t)1L << dib_info.bits_per_pixel;
    ssize_t stride = 4;

    // Write all red components
    for (ssize_t j = 0; j < total_pixels; j++) {
        base_q[j * stride] = (unsigned char)0;
    }
    // Write all green components
    for (ssize_t j = 0; j < total_pixels; j++) {
        base_q[j * stride + 1] = (unsigned char)0;
    }
    // Write all blue components
    for (ssize_t j = 0; j < total_pixels; j++) {
        base_q[j * stride + 2] = (unsigned char)0;
    }
    // Write all alpha components
    for (ssize_t j = 0; j < total_pixels; j++) {
        base_q[j * stride + 3] = (unsigned char)0;
    }

    q = base_q + (total_pixels * stride); // Advance q accordingly
    i = total_pixels; // Ensure i reflects loop completion
}

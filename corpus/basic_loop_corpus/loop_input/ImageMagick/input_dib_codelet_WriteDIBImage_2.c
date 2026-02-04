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

DIBInfo dib_info;
ssize_t i;
unsigned char *q;

unsigned char *q_storage;

void init_vars() {
    dib_info.bits_per_pixel = 8;
    size_t total_iterations = (ssize_t)1 << dib_info.bits_per_pixel;
    size_t data_size = total_iterations * 4;
    q_storage = (unsigned char *)calloc(data_size, 1);
    if (!q_storage) {
        exit(1);
    }
    q = q_storage;
    i = 0;
}
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

BMPInfo bmp_info;
size_t type;
ssize_t i;
unsigned char *q;

unsigned char *q_buffer;

void init_vars() {
    // Initialize bmp_info fields
    bmp_info.bits_per_pixel = 8;  // Controls loop iterations: 1 << 8 = 256
    bmp_info.file_size = 0;
    bmp_info.ba_offset = 0;
    bmp_info.offset_bits = 0;
    bmp_info.size = 0;
    bmp_info.width = 0;
    bmp_info.height = 0;
    bmp_info.planes = 1;
    bmp_info.compression = 0;
    bmp_info.image_size = 0;
    bmp_info.x_pixels = 0;
    bmp_info.y_pixels = 0;
    bmp_info.number_colors = 0;
    bmp_info.red_mask = 0;
    bmp_info.green_mask = 0;
    bmp_info.blue_mask = 0;
    bmp_info.alpha_mask = 0;
    bmp_info.colors_important = 0;
    bmp_info.colorspace = 0;
    bmp_info.red_primary.x = 0.0;
    bmp_info.red_primary.y = 0.0;
    bmp_info.red_primary.z = 0.0;
    bmp_info.green_primary.x = 0.0;
    bmp_info.green_primary.y = 0.0;
    bmp_info.green_primary.z = 0.0;
    bmp_info.blue_primary.x = 0.0;
    bmp_info.blue_primary.y = 0.0;
    bmp_info.blue_primary.z = 0.0;
    bmp_info.gamma_scale.x = 0.0;
    bmp_info.gamma_scale.y = 0.0;
    bmp_info.gamma_scale.z = 0.0;

    // Set type to ensure alpha channel is written (type > 2)
    type = 3;

    // Allocate enough memory so that the loop runs for measurable time
    // Each iteration writes 3 or 4 bytes. With bits_per_pixel=8, we have 256 iterations.
    // To make the loop take ~0.01 seconds, we may need to scale up data size.
    // But since loop count is fixed by bits_per_pixel, we cannot change it.
    // Instead, we interpret the intent as ensuring safe buffer bounds.

    // However, note: loop runs (1 << bits_per_pixel) times.
    // If we want more operations, increase bits_per_pixel.
    // Let's set bits_per_pixel = 20 -> 1M iterations, each writing up to 4 bytes -> ~3MB output.
    bmp_info.bits_per_pixel = 20;

    size_t num_iterations = (size_t)1 << bmp_info.bits_per_pixel;
    size_t buffer_size = num_iterations * 4;  // Max 4 bytes per iteration

    q_buffer = (unsigned char*)malloc(buffer_size);
    if (!q_buffer) {
        exit(1);
    }

    q = q_buffer;

    i = 0;
}
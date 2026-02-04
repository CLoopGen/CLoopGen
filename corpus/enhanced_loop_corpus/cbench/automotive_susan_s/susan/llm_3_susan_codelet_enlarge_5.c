#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *tmp_image;
extern int *x_size;
extern int *y_size;
extern int border;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Index Array Precomputation
    // Instead of computing indices repeatedly, we precompute access positions 
    // and use a strided traversal pattern that could benefit vectorization or cache tiling.

    int width = *x_size + 2 * border;
    int height = *y_size + 2 * border;
    int total_ops = border * height;
    int *indices = (int*)__builtin_alloca(total_ops * sizeof(int));

    // Precompute vertical stride indices: j * width for all j in [0, height)
    for (j = 0; j < height; j++) {
        int base = j * width;
        for (i = 0; i < border; i++) {
            indices[j * border + i] = base;
        }
    }

    for (i = 0; i < border; i++) {
        for (j = 0; j < *y_size + 2 * border; j++) {
            int idx = j * border + i;
            int base_offset = indices[idx];
            tmp_image[base_offset + border - 1 - i] = tmp_image[base_offset + border + i];
            tmp_image[base_offset + *x_size + border + i] = tmp_image[base_offset + *x_size + border - 1 - i];
        }
    }
}

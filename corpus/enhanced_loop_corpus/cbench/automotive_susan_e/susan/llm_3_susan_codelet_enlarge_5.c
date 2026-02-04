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



void loop() {
    // Variant 2: Strided memory access with reversed inner loop and stride-based indexing
    int width = *x_size + 2 * border;
    int total_elements = (*y_size + 2 * border) * width;
    for (i = 0; i < border; i++) {
        int left_src_step = width;
        int left_dst_step = width;
        int right_src_step = width;
        int right_dst_step = width;
        int left_src_base = border + i;
        int left_dst_base = border - 1 - i;
        int right_src_base = *x_size + border - 1 - i;
        int right_dst_base = *x_size + border + i;
        for (j = 0; j < *y_size + 2 * border; j++) {
            int src_index_left = left_src_base + j * left_src_step;
            int dst_index_left = left_dst_base + j * left_dst_step;
            int src_index_right = right_src_base + j * right_src_step;
            int dst_index_right = right_dst_base + j * right_dst_step;
            tmp_image[dst_index_left] = tmp_image[src_index_left];
            tmp_image[dst_index_right] = tmp_image[src_index_right];
        }
    }
}

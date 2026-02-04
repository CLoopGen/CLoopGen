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
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    // We refactor the indexing to use a base pointer and step through memory consecutively
    // by precomputing row strides and using direct pointer offsets for better spatial locality.

    int width = *x_size + 2 * border;
    uchar *img = tmp_image;
    
    for (i = 0; i < border; i++) {
        uchar *left_src_base = img + border + i;
        uchar *left_dst_base = img + border - 1 - i;
        uchar *right_src_base = img + *x_size + border - 1 - i;
        uchar *right_dst_base = img + *x_size + border + i;

        for (j = 0; j < *y_size + 2 * border; j++) {
            *(left_dst_base + j * width) = *(left_src_base + j * width);
            *(right_dst_base + j * width) = *(right_src_base + j * width);
        }
    }
}

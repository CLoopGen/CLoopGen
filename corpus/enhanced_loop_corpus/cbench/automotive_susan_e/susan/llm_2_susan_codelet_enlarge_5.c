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
    // Variant 1: Consecutive memory access by precomputing row base pointers
    int width = *x_size + 2 * border;
    for (i = 0; i < border; i++) {
        int left_src_offset = border + i;
        int left_dst_offset = border - 1 - i;
        int right_src_offset = *x_size + border - 1 - i;
        int right_dst_offset = *x_size + border + i;
        for (j = 0; j < *y_size + 2 * border; j++) {
            uchar *row_base = &tmp_image[j * width];
            row_base[left_dst_offset] = row_base[left_src_offset];
            row_base[right_dst_offset] = row_base[right_src_offset];
        }
    }
}

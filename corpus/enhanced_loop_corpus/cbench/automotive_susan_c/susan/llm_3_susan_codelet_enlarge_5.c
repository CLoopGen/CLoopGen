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
    // Variant 2: Strided Memory Access Pattern with transposed-like indexing
    // Instead of iterating j (column-major within rows), we reorganize access to exhibit stride
    // over rows for each fixed offset, promoting potential vectorization or cache line utilization.
    // We maintain the same logic but swap computational order subtly by unrolling symmetry.

    int width = *x_size + 2 * border;
    int total_elements = (*y_size + 2 * border) * width;

    // Perform two separate strided passes: one for left border, one for right
    for (i = 0; i < border; i++) {
        // Strided pass across all rows for left-side mirroring
        for (j = 0; j < *y_size + 2 * border; j++) {
            int index_left_src = j * width + border + i;
            int index_left_dst = j * width + border - 1 - i;
            tmp_image[index_left_dst] = tmp_image[index_left_src];
        }
        // Strided pass across all rows for right-side mirroring
        for (j = 0; j < *y_size + 2 * border; j++) {
            int index_right_src = j * width + *x_size + border - 1 - i;
            int index_right_dst = j * width + *x_size + border + i;
            tmp_image[index_right_dst] = tmp_image[index_right_src];
        }
    }
}

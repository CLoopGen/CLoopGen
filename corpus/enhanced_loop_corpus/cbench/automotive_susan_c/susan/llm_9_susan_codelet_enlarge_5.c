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
    int x_ext = *x_size + 2 * border;
    int total_ops = border * (*y_size + 2 * border);
    // Flatten nested loops into a single loop with increased arithmetic per iteration
    for (int idx = 0; idx < total_ops; idx++) {
        int j = idx / border; // Simulate outer loop index
        int i = idx % border; // Simulate inner loop index
        if (i == 0 && j >= *y_size + 2 * border) break; // Boundary check for safety

        int base_offset = j * x_ext;
        // Perform both assignments with precomputed offsets to increase arithmetic intensity
        int left_src = base_offset + border + i;
        int left_dst = base_offset + border - 1 - i;
        int right_src = base_offset + *x_size + border - 1 - i;
        int right_dst = base_offset + *x_size + border + i;

        tmp_image[left_dst] = tmp_image[left_src];
        tmp_image[right_dst] = tmp_image[right_src];
    }
}

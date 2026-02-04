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
    // Variant 1: Consecutive Memory Access Pattern using pointer arithmetic
    // The original nested loop is transformed to access memory in a more sequential manner
    // by precomputing row strides and using direct pointer increments.

    int width = *x_size + 2 * border;
    uchar *base_ptr = tmp_image;
    for (i = 0; i < border; i++) {
        uchar *row_start;
        for (j = 0; j < *y_size + 2 * border; j++) {
            row_start = base_ptr + j * width;
            // Left mirror: copy from inner right to outer left
            row_start[border - 1 - i] = row_start[border + i];
            // Right mirror: copy from inner left to outer right
            row_start[*x_size + border + i] = row_start[*x_size + border - 1 - i];
        }
    }
}

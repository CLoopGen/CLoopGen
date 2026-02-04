#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char uchar;

uchar *tmp_image;
int *x_size;
int *y_size;
int border;
int i;
int j;

void init_vars() {
    // Set image dimensions
    int width = 1024;
    int height = 1024;
    
    // Set border value
    border = 2;

    // Allocate and initialize x_size and y_size
    x_size = (int*)malloc(sizeof(int));
    y_size = (int*)malloc(sizeof(int));
    *x_size = width;
    *y_size = height;

    // Allocate tmp_image with padding: (width + 2*border) * (height + 2*border)
    int padded_width = *x_size + 2 * border;
    int padded_height = *y_size + 2 * border;
    tmp_image = (uchar*)calloc(padded_width * padded_height, sizeof(uchar));

    // Initialize tmp_image with dummy data to avoid undefined behavior
    for (int idx = 0; idx < padded_width * padded_height; idx++) {
        tmp_image[idx] = (uchar)(idx % 256);
    }
}
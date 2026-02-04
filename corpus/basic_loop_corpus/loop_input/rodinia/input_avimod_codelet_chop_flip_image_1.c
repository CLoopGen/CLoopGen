#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *image;
int height;
int width;
int top;
int left;
int height_new;
int width_new;
int i;
int j;
float *result;
float temp;

void init_vars() {
    // Set dimensions to achieve ~100ms runtime: use image size around 64-128MB
    width = 8192;
    height = 8192;
    top = 100;
    left = 100;
    height_new = 4096;
    width_new = 4096;

    // Ensure bounds: (i + top) < height, (j + left) < width
    // So we require: height_new <= height - top, width_new <= width - left
    if (height_new > height - top) height_new = height - top;
    if (width_new > width - left) width_new = width - left;

    // Allocate image as byte array of size height * width
    image = (char*)malloc(height * width * sizeof(char));
    if (!image) {
        fprintf(stderr, "Failed to allocate image\n");
        exit(1);
    }

    // Initialize image with pseudo-random data to ensure variability
    srand(time(NULL));
    for (int idx = 0; idx < height * width; idx++) {
        image[idx] = (char)(rand() % 256 - 128); // Range -128 to 127
    }

    // Allocate result array: height_new * width_new floats
    result = (float*)malloc(height_new * width_new * sizeof(float));
    if (!result) {
        fprintf(stderr, "Failed to allocate result\n");
        free(image);
        exit(1);
    }

    // Initialize loop indices
    i = 0;
    j = 0;
    temp = 0.0f;
}
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *dst;
float *src;
int dst_stridea;
int dst_strideb;
int src_stridea;
int src_strideb;
int i;

void init_vars() {
    const int size = 1 << 20; // ~4MB for src and dst (each float), aiming for ~0.01 sec runtime
    const int width = 16;
    const int height = size / (width * sizeof(float));
    
    // Ensure minimum height to run the loop meaningfully
    const int min_height = 1000;
    const int actual_height = height < min_height ? min_height : height;

    // Allocate memory with padding to prevent out-of-bounds access
    src = (float*)aligned_alloc(32, width * actual_height * sizeof(float));
    dst = (float*)aligned_alloc(32, width * actual_height * sizeof(float));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize strides
    src_stridea = 1;  // step within a row: consecutive elements
    src_strideb = width; // step between rows
    dst_stridea = 1;
    dst_strideb = width;

    // Initialize src data with non-zero values to allow meaningful computation
    for (int y = 0; y < actual_height; y++) {
        for (int x = 0; x < width; x++) {
            float val = (float)(x + y) * 0.01f;
            src[y * src_strideb + x * src_stridea] = val;
        }
    }

    // Zero-initialize dst
    for (int j = 0; j < width * actual_height; j++) {
        dst[j] = 0.0f;
    }

    // Initialize loop index
    i = 0;
}
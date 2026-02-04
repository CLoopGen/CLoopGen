#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

static JSAMPLE *inptr0_data;
static JSAMPLE *inptr1_data;
static JSAMPLE *inptr2_data;
static JSAMPLE *outptr_data;

JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;
JLONG rgb;
unsigned int r;
unsigned int g;
unsigned int b;

void init_vars() {
    const size_t total_input_size = 64 * 1024 * 1024; // ~64MB per channel for RGB
    const size_t num_pixels = total_input_size;
    
    inptr0_data = (JSAMPLE*)aligned_alloc(32, num_pixels * sizeof(JSAMPLE));
    inptr1_data = (JSAMPLE*)aligned_alloc(32, num_pixels * sizeof(JSAMPLE));
    inptr2_data = (JSAMPLE*)aligned_alloc(32, num_pixels * sizeof(JSAMPLE));
    outptr_data = (JSAMPLE*)aligned_alloc(32, num_pixels * 2 * sizeof(int)); // each pixel pair produces 8 bytes

    if (!inptr0_data || !inptr1_data || !inptr2_data || !outptr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_pixels; i++) {
        inptr0_data[i] = (JSAMPLE)((i * 7 + 13) % 256);
        inptr1_data[i] = (JSAMPLE)((i * 11 + 17) % 256);
        inptr2_data[i] = (JSAMPLE)((i * 13 + 19) % 256);
    }

    inptr0 = inptr0_data;
    inptr1 = inptr1_data;
    inptr2 = inptr2_data;
    outptr = outptr_data;

    num_cols = num_pixels;
    col = 0;
    rgb = 0;
    r = 0;
    g = 0;
    b = 0;
}
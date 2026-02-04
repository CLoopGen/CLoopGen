#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32;
typedef unsigned char uchar;
typedef short shrt;

uint32 imagewidth;
uchar *inptr;
shrt *nextptr;
uint32 j;

void init_vars() {
    size_t data_size = 64 << 20; // ~64 MB of input data to ensure ~0.01 sec runtime
    imagewidth = data_size / 3;  // Each iteration consumes 3 bytes from inptr

    // Allocate memory for inptr: imagewidth * 3 bytes
    inptr = (uchar *)malloc(imagewidth * 3 * sizeof(uchar));
    if (!inptr) {
        fprintf(stderr, "Failed to allocate inptr\n");
        exit(1);
    }

    // Initialize inptr with dummy data
    for (uint32 i = 0; i < imagewidth * 3; ++i) {
        inptr[i] = (uchar)(i & 0xFF);
    }

    // Allocate memory for nextptr: each iteration writes 3 shorts (6 bytes), total 3 * imagewidth elements
    nextptr = (shrt *)malloc(3 * imagewidth * sizeof(shrt));
    if (!nextptr) {
        fprintf(stderr, "Failed to allocate nextptr\n");
        free(inptr);
        exit(1);
    }

    // Initialize nextptr to zero
    memset(nextptr, 0, 3 * imagewidth * sizeof(shrt));
}
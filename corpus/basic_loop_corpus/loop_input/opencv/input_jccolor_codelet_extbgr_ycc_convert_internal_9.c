#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
JLONG *ctab;
JSAMPROW inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of RGB data (~0.01 sec estimate)
    num_cols = input_size / 3;

    // Allocate ctab: needs to cover indices up to (7 * (255+1)) + 255 = 7*256 + 255 = 2047
    ctab = (JLONG*)calloc(2048, sizeof(JLONG));
    if (!ctab) exit(1);
    for (int i = 0; i < 2048; i++) {
        ctab[i] = (JLONG)(i * 0x10000); // Set fixed-point scaling so that >>16 gives original index
    }

    // Allocate input buffer: 3 bytes per pixel
    JSAMPROW input_buffer = (JSAMPROW)calloc(input_size, sizeof(JSAMPLE));
    if (!input_buffer) exit(1);
    for (size_t i = 0; i < input_size; i++) {
        input_buffer[i] = (JSAMPLE)(i % 256);
    }
    inptr = input_buffer;

    // Allocate output buffers: one byte per pixel per channel
    outptr0 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    outptr1 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    outptr2 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    if (!outptr0 || !outptr1 || !outptr2) exit(1);

    col = 0;
}
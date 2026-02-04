#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

int y;
int cb;
int cr;
JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;
JSAMPLE *range_limit;
int *Crrtab;
int *Cbbtab;
JLONG *Crgtab;
JLONG *Cbgtab;
JLONG rgb;
unsigned int r;
unsigned int g;
unsigned int b;

#define DATA_SIZE (16 << 20)  // ~16MB of input data for sufficient runtime

void init_vars() {
    // Allocate and initialize range_limit: maps byte values [-512..767] to clamped byte range [0..255]
    range_limit = (JSAMPLE *)malloc(1024 * sizeof(JSAMPLE));
    for (int i = 0; i < 256; i++) range_limit[i + 256] = (JSAMPLE)i;
    for (int i = 0; i < 256; i++) range_limit[i] = 0;
    for (int i = 0; i < 256; i++) range_limit[i + 512] = 255;

    // C tables for color conversion (indexed by byte values 0..255)
    Crrtab = (int *)malloc(256 * sizeof(int));
    Cbbtab = (int *)malloc(256 * sizeof(int));
    Crgtab = (JLONG *)malloc(256 * sizeof(JLONG));
    Cbgtab = (JLONG *)malloc(256 * sizeof(JLONG));

    for (int i = 0; i < 256; i++) {
        int cr_val = i - 128;
        int cb_val = i - 128;
        Crrtab[i] = 1.402 * cr_val;
        Cbbtab[i] = 1.772 * cb_val;
        Crgtab[i] = (-0.714 * cr_val);
        Cbgtab[i] = (-0.344 * cb_val);
    }

    // Input image data: ensure size is even due to >>1 processing
    num_cols = DATA_SIZE / 2;  // Each iteration processes 2 pixels (4 bytes total per pixel group)
    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * 2 * sizeof(uint32_t));  // 2 pixels per loop, each 4 bytes

    // Initialize input pointers to start of buffers
    inptr0 += 0;
    inptr1 += 0;
    inptr2 += 0;

    // Fill input with dummy data to prevent undefined behavior
    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = rand() % 256;
        inptr1[i] = rand() % 256;
        inptr2[i] = rand() % 256;
    }

    // Reset inptrs to beginning for loop consumption
    inptr0 -= 0;
    inptr1 -= 0;
    inptr2 -= 0;
}
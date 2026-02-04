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

static JLONG *ctab_internal;
static JSAMPLE *inbuf;
static JSAMPLE *outbuf0;
static JSAMPLE *outbuf1;
static JSAMPLE *outbuf2;

void init_vars() {
    const int max_colors = 256;
    const int color_range_plus_1 = 255 + 1;
    const int ctab_size = 8 * color_range_plus_1;
    num_cols = 64 * 1024;  // ~64K pixels, input size ~256KB (4 bytes per pixel), reasonable for ~0.01s

    // Allocate ctab: needs to cover indices up to r + 7*(255+1) where r <= 255
    ctab_internal = (JLONG *)calloc(ctab_size, sizeof(JLONG));
    if (!ctab_internal) exit(1);
    for (int i = 0; i < ctab_size; i++) {
        ctab_internal[i] = (i % 256) << 16;  // Simulate some table mapping with high bits set
    }
    ctab = ctab_internal;

    // Allocate input buffer: 4 bytes per pixel (RGBX format)
    inbuf = (JSAMPLE *)malloc(num_cols * 4 * sizeof(JSAMPLE));
    if (!inbuf) exit(1);
    for (JDIMENSION i = 0; i < num_cols * 4; i++) {
        inbuf[i] = rand() % 256;
    }
    inptr = inbuf;

    // Allocate output buffers: one byte per pixel per channel
    outbuf0 = (JSAMPLE *)calloc(num_cols, sizeof(JSAMPLE));
    outbuf1 = (JSAMPLE *)calloc(num_cols, sizeof(JSAMPLE));
    outbuf2 = (JSAMPLE *)calloc(num_cols, sizeof(JSAMPLE));
    if (!outbuf0 || !outbuf1 || !outbuf2) exit(1);

    outptr0 = outbuf0;
    outptr1 = outbuf1;
    outptr2 = outbuf2;

    col = 0;
}
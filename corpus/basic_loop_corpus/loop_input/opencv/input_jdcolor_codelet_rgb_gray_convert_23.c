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
JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    num_cols = 65536; // Adjust to achieve ~0.01 sec runtime (tunable based on system)

    // Allocate ctab: needs to hold at least 3*(255+1) = 768 elements, but we make it larger safely
    ctab = (JLONG *)calloc(3 * (256), sizeof(JLONG));
    for (int i = 0; i < 256; i++) {
        ctab[i + 0 * 256] = i << 16;
        ctab[i + 1 * 256] = (i << 16) + 0x8000;
        ctab[i + 2 * 256] = (i << 16) + 0x4000;
    }

    // Allocate input and output row buffers
    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));

    // Initialize input pointers with sample data
    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)((i * 17) % 256);
        inptr1[i] = (JSAMPLE)((i * 19) % 256);
        inptr2[i] = (JSAMPLE)((i * 23) % 256);
    }
}
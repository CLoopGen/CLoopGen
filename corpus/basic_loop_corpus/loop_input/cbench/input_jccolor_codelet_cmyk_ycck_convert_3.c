#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef long INT32;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
INT32 *ctab;
JSAMPROW inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JSAMPROW outptr3;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    num_cols = 65536; // ~1MB of input data (65536 pixels * 4 bytes per pixel)

    inptr = (JSAMPROW)malloc(num_cols * 4 * sizeof(JSAMPLE));
    outptr0 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    outptr1 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    outptr2 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    outptr3 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));

    ctab = (INT32 *)calloc(8 * (255 + 1), sizeof(INT32));
    for (int i = 0; i < 8 * (256); i++) {
        ctab[i] = (INT32)(i * 1000); // arbitrary initialization to avoid zero values
    }

    for (JDIMENSION i = 0; i < num_cols * 4; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }
}
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
JLONG d0;
JLONG rgb;
unsigned int r;
unsigned int g;
unsigned int b;

#define DATA_SIZE (128 << 20) // 128 MB of input data

void init_vars() {
    // Allocate and initialize range_limit table (256 + 2 * 32768 entries as typical in JPEG)
    range_limit = (JSAMPLE*)malloc(32768 + 256 + 32768);
    for (int i = 0; i < 32768 + 256 + 32768; i++) {
        if (i < 32768) range_limit[i] = 0;
        else if (i >= 32768 + 256) range_limit[i] = 255;
        else range_limit[i] = (JSAMPLE)(i - 32768);
    }

    // Allocate color transform tables
    Crrtab = (int*)malloc(256 * sizeof(int));
    Cbbtab = (int*)malloc(256 * sizeof(int));
    Crgtab = (JLONG*)malloc(256 * sizeof(JLONG));
    Cbgtab = (JLONG*)malloc(256 * sizeof(JLONG));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = (i - 128) * 4; 
        Cbbtab[i] = (i - 128) * 4;
        Crgtab[i] = (JLONG)(-(i - 128)) * 2;
        Cbgtab[i] = (JLONG)(-(i - 128)) * 3;
    }

    // Calculate number of columns based on input size
    num_cols = DATA_SIZE / 2; // Each iteration processes two pixels

    // Allocate input rows: each row has num_cols elements, but we process pairs so need enough
    inptr0 = (JSAMPROW)malloc(num_cols * 2 * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * 2 * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * 2 * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * 4 * sizeof(JSAMPLE)); // 4 bytes per pixel pair

    // Initialize input data with non-zero values to avoid trivial optimization
    for (JDIMENSION i = 0; i < num_cols * 2; i++) {
        inptr0[i] = (JSAMPLE)(i % 251);
        inptr1[i] = (JSAMPLE)((i * 3) % 251);
        inptr2[i] = (JSAMPLE)((i * 7) % 251);
    }

    // Initialize state variables
    d0 = 0xABCDEF00;
    col = 0;
}
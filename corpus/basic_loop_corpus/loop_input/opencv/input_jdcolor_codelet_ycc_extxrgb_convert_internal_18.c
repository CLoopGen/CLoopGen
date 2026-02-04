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

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB total data to target ~0.01 sec runtime

void init_vars() {
    // Allocate input and output buffers
    inptr0 = (JSAMPROW)aligned_alloc(32, num_cols);
    inptr1 = (JSAMPROW)aligned_alloc(32, num_cols);
    inptr2 = (JSAMPROW)aligned_alloc(32, num_cols);
    outptr = (JSAMPROW)aligned_alloc(32, num_cols * 4);

    // Set num_cols to control data size: aim for large enough to take ~0.01s
    num_cols = DATA_SIZE / 4; // Each pixel takes 4 bytes in output

    // Re-allocate with correct num_cols
    free(inptr0);
    free(inptr1);
    free(inptr2);
    free(outptr);

    inptr0 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * 4 * sizeof(JSAMPLE));

    // Initialize range_limit: maps [-256..511] safely to [0..255]
    range_limit = (JSAMPLE *)malloc(512 + 256);
    for (int i = 0; i < 256; i++)
        range_limit[i] = 0;
    for (int i = 256; i < 512; i++)
        range_limit[i] = (JSAMPLE)(i - 256);
    for (int i = 512; i < 768; i++)
        range_limit[i] = 255;

    // Offset so that valid indices are from -256 to 511 -> base at 256
    range_limit += 256; // Now index -256 uses range_limit[-256+256]=range_limit[0]

    // Allocate and initialize C tables (used as lookup)
    Crrtab = (int *)malloc(256 * sizeof(int));
    Cbbtab = (int *)malloc(256 * sizeof(int));
    Crgtab = (JLONG *)malloc(256 * sizeof(JLONG));
    Cbgtab = (JLONG *)malloc(256 * sizeof(JLONG));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = ((i - 128) * 400) / 256;  // scaled contribution
        Cbbtab[i] = ((i - 128) * 400) / 256;
        Crgtab[i] = (JLONG)((i - 128) * 200);
        Cbgtab[i] = (JLONG)((i - 128) * 200);
    }

    // Initialize input data to prevent undefined behavior
    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = rand() % 256;
        inptr1[i] = rand() % 256;
        inptr2[i] = rand() % 256;
    }

    col = 0;
    y = 0;
    cb = 0;
    cr = 0;
}
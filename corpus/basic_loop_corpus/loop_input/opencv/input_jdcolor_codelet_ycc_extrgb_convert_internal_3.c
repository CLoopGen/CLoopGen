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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // Approx 64MB for ~0.01 sec runtime
    num_cols = data_size / 3; // Divide by 3 to account for 3 components per pixel

    // Allocate aligned memory for input and output rows
    inptr0 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)aligned_alloc(32, num_cols * 3 * sizeof(JSAMPLE));

    // Initialize input data with non-zero values
    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i % 256);
        inptr1[i] = (JSAMPLE)((i * 3) % 256);
        inptr2[i] = (JSAMPLE)((i * 5) % 256);
    }

    // Allocate and initialize range_limit (maps [-255..511] to [0..255])
    range_limit = (JSAMPLE *)aligned_alloc(32, 768 * sizeof(JSAMPLE));
    for (int i = 0; i < 768; i++) {
        range_limit[i] = (JSAMPLE)((i < 0) ? 0 : (i > 255) ? 255 : i);
    }

    // Allocate and initialize transform tables (size 256 for each)
    Crrtab = (int *)aligned_alloc(32, 256 * sizeof(int));
    Cbbtab = (int *)aligned_alloc(32, 256 * sizeof(int));
    Crgtab = (JLONG *)aligned_alloc(32, 256 * sizeof(JLONG));
    Cbgtab = (JLONG *)aligned_alloc(32, 256 * sizeof(JLONG));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = 11 * i;
        Cbbtab[i] = 12 * i;
        Crgtab[i] = (JLONG)(-5 * i);
        Cbgtab[i] = (JLONG)(-3 * i);
    }

    col = 0;
}
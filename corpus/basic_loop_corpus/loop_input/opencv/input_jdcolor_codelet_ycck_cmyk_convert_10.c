#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long INT32;

int y;
int cb;
int cr;
JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JSAMPROW inptr3;
JDIMENSION col;
JDIMENSION num_cols;
JSAMPLE *range_limit;
int *Crrtab;
int *Cbbtab;
INT32 *Crgtab;
INT32 *Cbgtab;

static JSAMPLE *outbuf;
static JSAMPLE *inbuf0;
static JSAMPLE *inbuf1;
static JSAMPLE *inbuf2;
static JSAMPLE *inbuf3;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB total input to target ~0.01s runtime

    // Allocate input and output buffers
    outbuf = (JSAMPLE*)aligned_alloc(32, data_size * 4);
    inbuf0 = (JSAMPLE*)aligned_alloc(32, data_size);
    inbuf1 = (JSAMPLE*)aligned_alloc(32, data_size);
    inbuf2 = (JSAMPLE*)aligned_alloc(32, data_size);
    inbuf3 = (JSAMPLE*)aligned_alloc(32, data_size);

    if (!outbuf || !inbuf0 || !inbuf1 || !inbuf2 || !inbuf3) {
        exit(1);
    }

    // Initialize sample data
    for (size_t i = 0; i < data_size; i++) {
        inbuf0[i] = (JSAMPLE)(i % 256);
        inbuf1[i] = (JSAMPLE)((i * 3) % 256);
        inbuf2[i] = (JSAMPLE)((i * 5) % 256);
        inbuf3[i] = (JSAMPLE)((i * 7) % 256);
    }

    // Set up pointers
    outptr = outbuf;
    inptr0 = inbuf0;
    inptr1 = inbuf1;
    inptr2 = inbuf2;
    inptr3 = inbuf3;
    num_cols = data_size;

    // Allocate and initialize range_limit (covers [-255..511] -> index 0..766)
    range_limit = (JSAMPLE*)malloc(767 * sizeof(JSAMPLE));
    if (!range_limit) exit(1);
    for (int i = 0; i < 767; i++) {
        int val = i - 255;
        range_limit[i] = (val < 0) ? 0 : (val > 255 ? 255 : val);
    }

    // Allocate and initialize tables (indexed by 0..255)
    Crrtab = (int*)malloc(256 * sizeof(int));
    Cbbtab = (int*)malloc(256 * sizeof(int));
    Crgtab = (INT32*)malloc(256 * sizeof(INT32));
    Cbgtab = (INT32*)malloc(256 * sizeof(INT32));
    if (!Crrtab || !Cbbtab || !Crgtab || !Cbgtab) exit(1);

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = (int)(1.402 * (i - 128));         // Y + Cr scaling
        Cbbtab[i] = (int)(1.772 * (i - 128));         // Y + Cb scaling
        Crgtab[i] = (INT32)(-0.714 * (i - 128) * 65536); // Q16 fixed-point
        Cbgtab[i] = (INT32)(-0.344 * (i - 128) * 65536); // Q16 fixed-point
    }
}
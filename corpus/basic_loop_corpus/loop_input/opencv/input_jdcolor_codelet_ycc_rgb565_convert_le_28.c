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

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024 / 6) // Each pixel uses 6 bytes (3 input rows), process 2 pixels per iteration

void init_vars() {
    const int range_limit_size = 1024;
    const int ctab_size = 256;

    range_limit = calloc(range_limit_size, sizeof(JSAMPLE));
    Crrtab = calloc(ctab_size, sizeof(int));
    Cbbtab = calloc(ctab_size, sizeof(int));
    Crgtab = calloc(ctab_size, sizeof(JLONG));
    Cbgtab = calloc(ctab_size, sizeof(JLONG));

    inptr0 = malloc(TOTAL_PIXELS * sizeof(JSAMPLE));
    inptr1 = malloc(TOTAL_PIXELS * sizeof(JSAMPLE));
    inptr2 = malloc(TOTAL_PIXELS * sizeof(JSAMPLE));
    outptr = malloc(TOTAL_PIXELS * 2); // 2 bytes per pixel output, two pixels per loop -> 4 bytes per iteration

    num_cols = TOTAL_PIXELS;

    for (int i = 0; i < range_limit_size; i++) {
        range_limit[i] = (JSAMPLE)((i > 255) ? 255 : (i < 0) ? 0 : i);
    }

    for (int i = 0; i < ctab_size; i++) {
        Crrtab[i] = 11 * i;
        Cbbtab[i] = 15 * i;
        Crgtab[i] = -5 * i;
        Cbgtab[i] = -3 * i;
    }

    for (int i = 0; i < TOTAL_PIXELS; i++) {
        inptr0[i] = rand() % 256;
        inptr1[i] = rand() % 256;
        inptr2[i] = rand() % 256;
    }

    col = 0;
}
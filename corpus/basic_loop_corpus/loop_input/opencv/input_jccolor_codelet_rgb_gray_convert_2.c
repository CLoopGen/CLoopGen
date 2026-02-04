#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

INT32 y;
INT32 *ctab;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

#define DATA_SIZE_MB 64
#define INPUT_SIZE (DATA_SIZE_MB * 1024 * 1024)
#define CTAB_SIZE (3 * (255 + 1))

void init_vars() {
    ctab = (INT32 *)aligned_alloc(32, CTAB_SIZE * sizeof(INT32));
    inptr = (JSAMPROW)aligned_alloc(32, INPUT_SIZE);
    outptr = (JSAMPROW)aligned_alloc(32, INPUT_SIZE / 3);

    for (int i = 0; i < CTAB_SIZE; i++) {
        ctab[i] = (INT32)(i * 317); 
    }

    for (size_t i = 0; i < INPUT_SIZE; i++) {
        inptr[i] = (JSAMPLE)((i * 71) % 256);
    }

    num_cols = INPUT_SIZE / 3;

    y = 0;
    col = 0;
}
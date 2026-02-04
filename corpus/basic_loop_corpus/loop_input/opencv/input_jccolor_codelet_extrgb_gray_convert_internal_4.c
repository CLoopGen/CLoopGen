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
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    num_cols = 64 * 1024 * 3; // ~192KB of output, input will be 3 times larger

    ctab = (JLONG *)calloc(3 * (255 + 1), sizeof(JLONG));
    if (!ctab) exit(1);

    inptr = (JSAMPROW)malloc(num_cols * 3 * sizeof(JSAMPLE));
    if (!inptr) exit(1);

    for (JDIMENSION i = 0; i < num_cols * 3; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    outptr = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    if (!outptr) exit(1);

    for (int i = 0; i < 3 * (255 + 1); i++) {
        ctab[i] = (JLONG)(i * 1000); 
    }
}
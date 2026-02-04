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
JDIMENSION col;
JDIMENSION num_cols;
JSAMPLE *range_limit;
int *Crrtab;
int *Cbbtab;
INT32 *Crgtab;
INT32 *Cbgtab;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // Approximate input size for ~0.01 sec runtime
    num_cols = data_size / sizeof(JSAMPLE);

    posix_memalign((void**)&inptr0, 32, num_cols * sizeof(JSAMPLE));
    posix_memalign((void**)&inptr1, 32, num_cols * sizeof(JSAMPLE));
    posix_memalign((void**)&inptr2, 32, num_cols * sizeof(JSAMPLE));
    posix_memalign((void**)&outptr, 32, 3 * num_cols * sizeof(JSAMPLE));

    posix_memalign((void**)&range_limit, 32, 512 * sizeof(JSAMPLE));
    for (int i = 0; i < 512; i++) {
        range_limit[i] = (JSAMPLE)((i < 256) ? ((i < 0) ? 0 : i) : 255);
    }

    posix_memalign((void**)&Crrtab, 32, 256 * sizeof(int));
    posix_memalign((void**)&Cbbtab, 32, 256 * sizeof(int));
    posix_memalign((void**)&Crgtab, 32, 256 * sizeof(INT32));
    posix_memalign((void**)&Cbgtab, 32, 256 * sizeof(INT32));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = 113 * i;
        Cbbtab[i] = 113 * i;
        Crgtab[i] = (INT32)(-38 * i);
        Cbgtab[i] = (INT32)(-18 * i);
    }

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i % 256);
        inptr1[i] = (JSAMPLE)((i * 7) % 256);
        inptr2[i] = (JSAMPLE)((i * 13) % 256);
    }
}
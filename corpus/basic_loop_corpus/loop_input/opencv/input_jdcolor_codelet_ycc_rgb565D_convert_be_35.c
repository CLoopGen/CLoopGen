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

#define DATA_SIZE (64 * 1024 * 1024)

JSAMPLE *in_buffer0;
JSAMPLE *in_buffer1;
JSAMPLE *in_buffer2;
JSAMPLE *out_buffer;
JSAMPLE *range_limit_mem;
int *Crrtab_mem;
int *Cbbtab_mem;
JLONG *Crgtab_mem;
JLONG *Cbgtab_mem;

void init_vars() {
    const int range_limit_size = 512;
    const int color_table_size = 256;
    const JDIMENSION cols = DATA_SIZE / 3;
    
    in_buffer0 = (JSAMPLE*)malloc(cols * sizeof(JSAMPLE));
    in_buffer1 = (JSAMPLE*)malloc(cols * sizeof(JSAMPLE));
    in_buffer2 = (JSAMPLE*)malloc(cols * sizeof(JSAMPLE));
    out_buffer = (JSAMPLE*)malloc(cols * 2 * sizeof(JLONG));
    range_limit_mem = (JSAMPLE*)malloc(range_limit_size * sizeof(JSAMPLE));
    Crrtab_mem = (int*)malloc(color_table_size * sizeof(int));
    Cbbtab_mem = (int*)malloc(color_table_size * sizeof(int));
    Crgtab_mem = (JLONG*)malloc(color_table_size * sizeof(JLONG));
    Cbgtab_mem = (JLONG*)malloc(color_table_size * sizeof(JLONG));

    for (size_t i = 0; i < cols; i++) {
        in_buffer0[i] = (JSAMPLE)(i % 256);
        in_buffer1[i] = (JSAMPLE)((i * 3) % 256);
        in_buffer2[i] = (JSAMPLE)((i * 7) % 256);
    }

    for (int i = 0; i < range_limit_size; i++) {
        range_limit_mem[i] = (JSAMPLE)((i < 0) ? 0 : (i > 255) ? 255 : i);
    }

    for (int i = 0; i < color_table_size; i++) {
        Crrtab_mem[i] = 113 * i;
        Cbbtab_mem[i] = 98 * i;
        Crgtab_mem[i] = -38 * i;
        Cbgtab_mem[i] = -18 * i;
    }

    y = 128;
    cb = 128;
    cr = 128;
    r = 128;
    g = 128;
    b = 128;
    d0 = 0xABCDEF00;
    rgb = 0;

    inptr0 = in_buffer0;
    inptr1 = in_buffer1;
    inptr2 = in_buffer2;
    outptr = out_buffer;
    range_limit = range_limit_mem + 256;
    Crrtab = Crrtab_mem;
    Cbbtab = Cbbtab_mem;
    Crgtab = Crgtab_mem;
    Cbgtab = Cbgtab_mem;
    num_cols = cols;
}
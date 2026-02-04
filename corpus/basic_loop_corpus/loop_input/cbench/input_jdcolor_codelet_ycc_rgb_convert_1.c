#include <stdio.h>
#include <inttypes.h>

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

#define DATA_SIZE (64 * 1024 * 1024) // ~64 MB of input data

static JSAMPLE inbuf0[DATA_SIZE];
static JSAMPLE inbuf1[DATA_SIZE];
static JSAMPLE inbuf2[DATA_SIZE];
static JSAMPLE outbuf[3 * DATA_SIZE];
static JSAMPLE range_limit_data[1024];
static int Crrtab_data[256];
static int Cbbtab_data[256];
static INT32 Crgtab_data[256];
static INT32 Cbgtab_data[256];

void init_vars() {
    num_cols = DATA_SIZE;

    inptr0 = inbuf0;
    inptr1 = inbuf1;
    inptr2 = inbuf2;
    outptr = outbuf;

    range_limit = range_limit_data;
    Crrtab = Crrtab_data;
    Cbbtab = Cbbtab_data;
    Crgtab = Crgtab_data;
    Cbgtab = Cbgtab_data;

    for (int i = 0; i < DATA_SIZE; i++) {
        inbuf0[i] = i % 256;
        inbuf1[i] = (i + 32) % 256;
        inbuf2[i] = (i + 64) % 256;
    }

    for (int i = 0; i < 1024; i++) {
        range_limit_data[i] = (i < 0) ? 0 : ((i > 255) ? 255 : i);
    }

    for (int i = 0; i < 256; i++) {
        Crrtab_data[i] = i * 3;
        Cbbtab_data[i] = i * 5;
        Crgtab_data[i] = i * 13107; // example fixed-point coefficient
        Cbgtab_data[i] = i * 25907; // example fixed-point coefficient
    }
}
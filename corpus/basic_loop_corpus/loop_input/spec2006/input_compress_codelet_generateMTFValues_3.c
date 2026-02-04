#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

typedef struct {
    char *next_in;
    unsigned int avail_in;
    unsigned int total_in_lo32;
    unsigned int total_in_hi32;
    char *next_out;
    unsigned int avail_out;
    unsigned int total_out_lo32;
    unsigned int total_out_hi32;
    void *state;
    void *(*bzalloc)(void *, int, int);
    void (*bzfree)(void *, void *);
    void *opaque;
} bz_stream;

typedef int Int32;

typedef unsigned int UInt32;

typedef unsigned char UChar;

typedef unsigned short UInt16;

typedef unsigned char Bool;

typedef struct {
    bz_stream *strm;
    Int32 mode;
    Int32 state;
    UInt32 avail_in_expect;
    UInt32 *arr1;
    UInt32 *arr2;
    UInt32 *ftab;
    Int32 origPtr;
    UInt32 *ptr;
    UChar *block;
    UInt16 *mtfv;
    UChar *zbits;
    Int32 workFactor;
    UInt32 state_in_ch;
    Int32 state_in_len;
    Int32 rNToGo;
    Int32 rTPos;
    Int32 nblock;
    Int32 nblockMAX;
    Int32 numZ;
    Int32 state_out_pos;
    Int32 nInUse;
    Bool inUse[256];
    UChar unseqToSeq[256];
    UInt32 bsBuff;
    Int32 bsLive;
    UInt32 blockCRC;
    UInt32 combinedCRC;
    Int32 verbosity;
    Int32 blockNo;
    Int32 blockSize100k;
    Int32 nMTF;
    Int32 mtfFreq[258];
    UChar selector[18002];
    UChar selectorMtf[18002];
    UChar len[6][258];
    Int32 code[6][258];
    Int32 rfreq[6][258];
    UInt32 len_pack[258][4];
} EState;

EState *s;
UChar yy[256];
Int32 i;
Int32 j;
Int32 zPend;
Int32 wr;
UInt32 *ptr;
UChar *block;
UInt16 *mtfv;

void init_vars() {
    const Int32 data_size = 1 << 20; // ~1MB of input data

    s = (EState*)calloc(1, sizeof(EState));
    if (!s) exit(1);

    s->nblock = data_size;
    s->nblockMAX = data_size;
    s->mtfFreq[0] = 0;
    s->mtfFreq[1] = 0;
    for (int idx = 2; idx < 258; idx++) {
        s->mtfFreq[idx] = 0;
    }

    ptr = (UInt32*)malloc(s->nblock * sizeof(UInt32));
    block = (UChar*)malloc(s->nblock * sizeof(UChar));
    mtfv = (UInt16*)malloc(s->nblock * 2 * sizeof(UInt16)); // conservative size

    if (!ptr || !block || !mtfv) exit(1);

    for (Int32 idx = 0; idx < s->nblock; idx++) {
        ptr[idx] = (idx + 1) % s->nblock;
        block[idx] = (UChar)(idx % 256);
    }

    for (int idx = 0; idx < 256; idx++) {
        s->unseqToSeq[idx] = (UChar)idx;
    }

    yy[0] = 42;
    for (int idx = 1; idx < 256; idx++) {
        yy[idx] = (UChar)((idx + 1) % 256);
    }

    zPend = 0;
    wr = 0;
}
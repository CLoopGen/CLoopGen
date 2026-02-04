#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

void init_vars() {
    s = (EState*)calloc(1, sizeof(EState));
    if (!s) return;

    s->nInUse = 256;
    for (int j = 0; j < 256; j++) {
        s->inUse[j] = 1;
        s->unseqToSeq[j] = (UChar)j;
        s->mtfFreq[j] = 1;
    }
    s->mtfFreq[256] = 1;
    s->mtfFreq[257] = 1;

    s->blockSize100k = 10;
    s->nblockMAX = s->blockSize100k * 100000;
    s->nblock = s->nblockMAX;

    s->arr1 = (UInt32*)malloc(s->nblockMAX * sizeof(UInt32));
    s->arr2 = (UInt32*)malloc(s->nblockMAX * sizeof(UInt32));
    s->ftab = (UInt32*)malloc(65537 * sizeof(UInt32));
    s->ptr = (UInt32*)malloc(s->nblockMAX * sizeof(UInt32));
    s->block = (UChar*)malloc(s->nblockMAX + 20);
    s->mtfv = (UInt16*)malloc(2 * (s->nMTF + 1) * sizeof(UInt16));
    s->zbits = (UChar*)malloc(500000);

    if (s->arr1) memset(s->arr1, 0, s->nblockMAX * sizeof(UInt32));
    if (s->arr2) memset(s->arr2, 0, s->nblockMAX * sizeof(UInt32));
    if (s->ftab) memset(s->ftab, 0, 65537 * sizeof(UInt32));
    if (s->ptr) for (Int32 j = 0; j < s->nblockMAX; j++) s->ptr[j] = j;
    if (s->block) for (Int32 j = 0; j < s->nblockMAX + 20; j++) s->block[j] = (UChar)(j % 256);
    if (s->mtfv) memset(s->mtfv, 0, 2 * (s->nMTF + 1) * sizeof(UInt16));
    if (s->zbits) memset(s->zbits, 0, 500000);

    s->workFactor = 30;
    s->bsLive = 0;
    s->bsBuff = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->verbosity = 0;
    s->blockNo = 1;
    s->nMTF = 258;

    for (int k = 0; k < 6; k++) {
        for (int j = 0; j < 258; j++) {
            s->len[k][j] = 1;
            s->code[k][j] = j;
            s->rfreq[k][j] = 1;
        }
    }

    for (int j = 0; j < 18002; j++) {
        s->selector[j] = (j % 6);
        s->selectorMtf[j] = (j % 6);
    }

    for (int j = 0; j < 258; j++) {
        for (int k = 0; k < 4; k++) {
            s->len_pack[j][k] = 0;
        }
    }

    bz_stream *strm = (bz_stream*)malloc(sizeof(bz_stream));
    if (strm) {
        memset(strm, 0, sizeof(bz_stream));
    }
    s->strm = strm;

    i = 0;
    for (int j = 0; j < 256; j++) {
        yy[j] = 0;
    }
}
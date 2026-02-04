#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned char UChar;
typedef int Int32;
typedef unsigned int UInt32;
typedef unsigned short UInt16;
typedef unsigned char Bool;

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

UChar pos[6];
UChar ll_i;
UChar tmp2;
UChar tmp;
EState *s;
Int32 i;
Int32 j;
Int32 nSelectors;

void init_vars() {
    s = (EState*)calloc(1, sizeof(EState));
    if (!s) return;

    nSelectors = 18000;

    for (int idx = 0; idx < 6; idx++) {
        pos[idx] = idx;
    }

    for (int idx = 0; idx < nSelectors; idx++) {
        s->selector[idx] = (UChar)(idx % 6);
    }

    for (int idx = 0; idx < 256; idx++) {
        s->inUse[idx] = (idx % 7) == 0;
    }

    s->nInUse = 0;
    for (int idx = 0; idx < 256; idx++) {
        if (s->inUse[idx]) s->nInUse++;
    }

    s->blockSize100k = 9;
    s->blockNo = 1;
    s->verbosity = 0;
    s->workFactor = 30;
    s->state = 0;
    s->mode = 1;
    s->avail_in_expect = 0;
    s->bsLive = 0;
    s->bsBuff = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->rNToGo = 50;
    s->rTPos = 0;
    s->nblock = 0;
    s->nblockMAX = 900000;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->origPtr = 0;
    s->state_in_ch = 0;
    s->state_in_len = 0;
    s->nMTF = 258;

    for (int idx = 0; idx < 258; idx++) {
        s->mtfFreq[idx] = 1;
    }

    for (int g = 0; g < 6; g++) {
        for (int idx = 0; idx < 258; idx++) {
            s->len[g][idx] = (UChar)((idx % 3) + 1);
        }
        for (int idx = 0; idx < 258; idx++) {
            s->code[g][idx] = idx;
        }
        for (int idx = 0; idx < 258; idx++) {
            s->rfreq[g][idx] = idx + 1;
        }
    }

    for (int idx = 0; idx < 258; idx++) {
        for (int k = 0; k < 4; k++) {
            s->len_pack[idx][k] = ((UInt32)idx) << (k * 8);
        }
    }

    s->strm = (bz_stream*)calloc(1, sizeof(bz_stream));
    if (!s->strm) {
        free(s);
        s = NULL;
        return;
    }

    s->arr1 = (UInt32*)calloc(100000, sizeof(UInt32));
    s->arr2 = (UInt32*)calloc(100000, sizeof(UInt32));
    s->ftab = (UInt32*)calloc(65537, sizeof(UInt32));
    s->ptr = (UInt32*)calloc(900000, sizeof(UInt32));
    s->block = (UChar*)calloc(900000, sizeof(UChar));
    s->mtfv = (UInt16*)calloc(900000, sizeof(UInt16));
    s->zbits = (UChar*)calloc(20000, sizeof(UChar));

    for (int idx = 0; idx < 256; idx++) {
        s->unseqToSeq[idx] = (UChar)idx;
    }
}
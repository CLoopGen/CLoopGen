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
UInt32 *ptr;
Int32 i;

void init_vars() {
    s = (EState*)calloc(1, sizeof(EState));
    if (!s) return;

    s->nblockMAX = 65536;
    s->nblock = 65536;
    s->origPtr = -1;

    ptr = (UInt32*)calloc(s->nblock, sizeof(UInt32));
    if (!ptr) {
        free(s);
        return;
    }

    s->ptr = ptr;

    for (Int32 j = 0; j < s->nblock; j++) {
        ptr[j] = 1;
    }

    ptr[s->nblock - 1] = 0;

    s->arr1 = (UInt32*)calloc(s->nblock, sizeof(UInt32));
    s->arr2 = (UInt32*)calloc(s->nblock, sizeof(UInt32));
    s->ftab = (UInt32*)calloc(65537, sizeof(UInt32));

    s->block = (UChar*)calloc(s->nblock + 1, sizeof(UChar));
    s->mtfv = (UInt16*)calloc(2 * s->nblock, sizeof(UInt16));
    s->zbits = (UChar*)calloc(s->nblock / 8 + 1, sizeof(UChar));

    s->strm = (bz_stream*)calloc(1, sizeof(bz_stream));

    s->workFactor = 30;
    s->verbosity = 0;
    s->blockNo = 1;
    s->blockSize100k = 9;
    s->nMTF = 258;
    s->bsLive = 0;
    s->bsBuff = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;

    for (int j = 0; j < 256; j++) {
        s->inUse[j] = (j >= 32 && j <= 126) ? 1 : 0;
        s->unseqToSeq[j] = (UChar)j;
    }
    s->nInUse = 95;

    for (int g = 0; g < 6; g++) {
        for (int v = 0; v < 258; v++) {
            s->len[g][v] = 0x10;
            s->code[g][v] = v;
            s->rfreq[g][v] = 0;
        }
    }

    for (int v = 0; v < 258; v++) {
        for (int h = 0; h < 4; h++) {
            s->len_pack[v][h] = 0;
        }
    }

    for (int j = 0; j < 18002; j++) {
        s->selector[j] = 0;
        s->selectorMtf[j] = 0;
    }
}
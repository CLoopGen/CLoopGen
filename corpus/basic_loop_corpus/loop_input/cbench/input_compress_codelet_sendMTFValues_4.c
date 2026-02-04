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

static bz_stream stream_instance;
EState *s;
Int32 v;
Int32 t;
Int32 alphaSize = 258;

void init_vars() {
    s = (EState*)calloc(1, sizeof(EState));
    if (!s) return;

    s->strm = &stream_instance;
    s->nblockMAX = 900000;
    s->blockSize100k = 9;
    s->arr1 = (UInt32*)malloc(s->nblockMAX * sizeof(UInt32));
    s->arr2 = (UInt32*)malloc(s->nblockMAX * sizeof(UInt32));
    s->ftab = (UInt32*)malloc(65537 * sizeof(UInt32));
    s->ptr = (UInt32*)malloc(s->nblockMAX * sizeof(UInt32));
    s->block = (UChar*)malloc(s->nblockMAX + 50);
    s->mtfv = (UInt16*)malloc(2 * s->nblockMAX * sizeof(UInt16));
    s->zbits = (UChar*)malloc(s->nblockMAX * sizeof(UChar));

    if (s->arr1) memset(s->arr1, 0, s->nblockMAX * sizeof(UInt32));
    if (s->arr2) memset(s->arr2, 0, s->nblockMAX * sizeof(UInt32));
    if (s->ftab) memset(s->ftab, 0, 65537 * sizeof(UInt32));
    if (s->ptr) memset(s->ptr, 0, s->nblockMAX * sizeof(UInt32));
    if (s->block) memset(s->block, 0, s->nblockMAX + 50);
    if (s->mtfv) memset(s->mtfv, 0, 2 * s->nblockMAX * sizeof(UInt16));
    if (s->zbits) memset(s->zbits, 0, s->nblockMAX * sizeof(UChar));

    s->nInUse = 256;
    for (int i = 0; i < 256; i++) {
        s->inUse[i] = (i % 7 != 0);
        s->unseqToSeq[i] = (UChar)i;
    }

    s->workFactor = 30;
    s->verbosity = 0;
    s->blockNo = 1;
    s->origPtr = 0;
    s->bsLive = 0;
    s->bsBuff = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->state = 0;
    s->mode = 1;
    s->avail_in_expect = 0;
    s->rNToGo = 50;
    s->rTPos = 0;
    s->nblock = 0;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->nMTF = 258;

    for (int i = 0; i < 258; i++) {
        s->mtfFreq[i] = 1;
        for (int j = 0; j < 6; j++) {
            s->code[j][i] = 0;
            s->rfreq[j][i] = 0;
        }
        if (i < 18002) {
            s->selector[i] = (i % 6);
            s->selectorMtf[i] = (i % 6);
        }
        for (int j = 0; j < 4; j++) {
            s->len_pack[i][j] = 0;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 258; j++) {
            s->len[i][j] = 0;
        }
    }

    alphaSize = 258;
    v = 0;
    t = 0;
}
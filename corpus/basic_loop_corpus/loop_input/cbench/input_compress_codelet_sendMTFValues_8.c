#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

typedef int Int32;

typedef unsigned int UInt32;

typedef unsigned char UChar;

typedef unsigned short UInt16;

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

Bool inUse16[16];

EState *s;
Int32 i;
Int32 j;

static bz_stream stream_storage;
static EState estate_storage;
static UInt32 ftab_storage[262144]; // typical size used in bzip2

void init_vars() {
    s = &estate_storage;
    s->strm = &stream_storage;
    s->mode = 0;
    s->state = 0;
    s->avail_in_expect = 0;
    s->arr1 = NULL;
    s->arr2 = NULL;
    s->ftab = ftab_storage;
    s->origPtr = 0;
    s->ptr = NULL;
    s->block = (UChar*)malloc(900000); // ~900KB for block
    s->mtfv = (UInt16*)malloc(18002 * sizeof(UInt16));
    s->zbits = (UChar*)malloc(18002);
    s->workFactor = 0;
    s->state_in_ch = 0;
    s->state_in_len = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->nblock = 0;
    s->nblockMAX = 900000;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->nInUse = 0;
    for (int idx = 0; idx < 256; idx++) {
        s->inUse[idx] = (idx % 17 == 0) ? ((Bool)1) : ((Bool)0); // ensure some are set
    }
    for (int idx = 0; idx < 256; idx++) {
        s->unseqToSeq[idx] = (UChar)idx;
    }
    s->bsBuff = 0;
    s->bsLive = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->verbosity = 0;
    s->blockNo = 1;
    s->blockSize100k = 9; // ~900KB data
    s->nMTF = 0;
    for (int idx = 0; idx < 258; idx++) {
        s->mtfFreq[idx] = 1;
    }
    for (int idx = 0; idx < 18002; idx++) {
        s->selector[idx] = (UChar)(idx % 6);
        s->selectorMtf[idx] = (UChar)(idx % 6);
    }
    for (int g = 0; g < 6; g++) {
        for (int idx = 0; idx < 258; idx++) {
            s->len[g][idx] = (UChar)((g + idx) % 6 + 1);
            s->code[g][idx] = 0;
            s->rfreq[g][idx] = 1;
        }
    }
    for (int idx = 0; idx < 258; idx++) {
        for (int k = 0; k < 4; k++) {
            s->len_pack[idx][k] = 0;
        }
    }

    i = 0;
    j = 0;

    for (int idx = 0; idx < 16; idx++) {
        inUse16[idx] = 0;
    }
}
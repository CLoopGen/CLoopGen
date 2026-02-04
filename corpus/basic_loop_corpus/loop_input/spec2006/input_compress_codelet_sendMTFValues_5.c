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
Int32 gs;
Int32 ge;
Int32 alphaSize = 258;
Int32 nPart = 6;

void init_vars() {
    s = (EState*)calloc(1, sizeof(EState));
    s->strm = &stream_instance;
    s->mode = 1;
    s->state = 0;
    s->avail_in_expect = 0;
    s->arr1 = (UInt32*)calloc(100000, sizeof(UInt32));
    s->arr2 = (UInt32*)calloc(100000, sizeof(UInt32));
    s->ftab = (UInt32*)calloc(65536, sizeof(UInt32));
    s->origPtr = 0;
    s->ptr = (UInt32*)calloc(900000, sizeof(UInt32));
    s->block = (UChar*)calloc(900000, sizeof(UChar));
    s->mtfv = (UInt16*)calloc(900000, sizeof(UInt16));
    s->zbits = (UChar*)calloc(900000, sizeof(UChar));
    s->workFactor = 30;
    s->state_in_ch = 0;
    s->state_in_len = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->nblock = 0;
    s->nblockMAX = 900000;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->nInUse = 256;
    for (int i = 0; i < 256; i++) {
        s->inUse[i] = 1;
        s->unseqToSeq[i] = (UChar)i;
    }
    memset(s->mtfFreq, 0, sizeof(s->mtfFreq));
    memset(s->selector, 0, sizeof(s->selector));
    memset(s->selectorMtf, 0, sizeof(s->selectorMtf));
    memset(s->len, 0, sizeof(s->len));
    memset(s->code, 0, sizeof(s->code));
    memset(s->rfreq, 0, sizeof(s->rfreq));
    memset(s->len_pack, 0, sizeof(s->len_pack));

    gs = 100;
    ge = 200;
}
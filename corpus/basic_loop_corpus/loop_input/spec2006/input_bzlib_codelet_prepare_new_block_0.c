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
Int32 i;

static UInt32 arr1_data[1600000];
static UInt32 arr2_data[1600000];
static UInt32 ftab_data[262144];
static UInt32 ptr_data[1600000];
static UChar block_data[1600000];
static UInt16 mtfv_data[18002];
static UChar zbits_data[10000];

void init_vars() {
    s = (EState*)calloc(1, sizeof(EState));
    if (!s) return;

    s->strm = &stream_instance;
    s->mode = 0;
    s->state = 0;
    s->avail_in_expect = 0;
    s->arr1 = arr1_data;
    s->arr2 = arr2_data;
    s->ftab = ftab_data;
    s->origPtr = 0;
    s->ptr = ptr_data;
    s->block = block_data;
    s->mtfv = mtfv_data;
    s->zbits = zbits_data;
    s->workFactor = 0;
    s->state_in_ch = 0;
    s->state_in_len = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->nblock = 0;
    s->nblockMAX = 1600000;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->nInUse = 0;
    for (int j = 0; j < 256; j++) {
        s->inUse[j] = 0;
    }
    for (int j = 0; j < 256; j++) {
        s->unseqToSeq[j] = (UChar)j;
    }
    s->bsBuff = 0;
    s->bsLive = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->verbosity = 0;
    s->blockNo = 1;
    s->blockSize100k = 9; // ~900KB data
    s->nMTF = 0;
    for (int j = 0; j < 258; j++) {
        s->mtfFreq[j] = 0;
    }
    for (int j = 0; j < 18002; j++) {
        s->selector[j] = 0;
        s->selectorMtf[j] = 0;
    }
    for (int k = 0; k < 6; k++) {
        for (int j = 0; j < 258; j++) {
            s->len[k][j] = 0;
            s->code[k][j] = 0;
            s->rfreq[k][j] = 0;
        }
    }
    for (int j = 0; j < 258; j++) {
        for (int k = 0; k < 4; k++) {
            s->len_pack[j][k] = 0;
        }
    }

    memset(arr1_data, 0, sizeof(arr1_data));
    memset(arr2_data, 0, sizeof(arr2_data));
    memset(ftab_data, 0, sizeof(ftab_data));
    memset(ptr_data, 0, sizeof(ptr_data));
    memset(block_data, 0, sizeof(block_data));
    memset(mtfv_data, 0, sizeof(mtfv_data));
    memset(zbits_data, 0, sizeof(zbits_data));
}
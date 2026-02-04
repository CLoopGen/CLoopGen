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

static bz_stream strm_instance;
static UInt32 arr1_data[1600000]; // ~6.4MB
static UInt32 arr2_data[1600000];
static UInt32 ftab_data[262144];
static UInt32 ptr_data[1600000];
static UChar block_data[1600000];
static UInt16 mtfv_data[18002];
static UChar zbits_data[100000];
static EState s_instance;

EState *s = &s_instance;
Int32 i;

void init_vars() {
    // Initialize the stream
    memset(&strm_instance, 0, sizeof(bz_stream));
    s->strm = &strm_instance;

    // Basic scalar values
    s->mode = 1;
    s->state = 0;
    s->avail_in_expect = 0;
    s->origPtr = 0;
    s->workFactor = 50;
    s->state_in_ch = 0;
    s->state_in_len = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->nblock = 0;
    s->nblockMAX = 1600000;  // matches block size
    s->numZ = 0;
    s->state_out_pos = 0;
    s->nInUse = 0;
    s->bsBuff = 0;
    s->bsLive = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->verbosity = 0;
    s->blockNo = 1;
    s->blockSize100k = 16;  // 1.6MB block size
    s->nMTF = 0;

    // Initialize arrays to zero
    memset(s->mtfFreq, 0, sizeof(s->mtfFreq));
    memset(s->selector, 0, sizeof(s->selector));
    memset(s->selectorMtf, 0, sizeof(s->selectorMtf));
    memset(s->len, 0, sizeof(s->len));
    memset(s->code, 0, sizeof(s->code));
    memset(s->rfreq, 0, sizeof(s->rfreq));
    memset(s->len_pack, 0, sizeof(s->len_pack));
    memset(s->unseqToSeq, 0, sizeof(s->unseqToSeq));

    // Pointers to allocated buffers
    s->arr1 = arr1_data;
    s->arr2 = arr2_data;
    s->ftab = ftab_data;
    s->ptr = ptr_data;
    s->block = block_data;
    s->mtfv = mtfv_data;
    s->zbits = zbits_data;

    // Ensure inUse is initialized (will be overwritten by loop, but clear first)
    memset(s->inUse, 0, sizeof(s->inUse));
}
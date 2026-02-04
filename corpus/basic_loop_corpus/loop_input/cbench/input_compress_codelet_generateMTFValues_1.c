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
Int32 i;
Int32 EOB;

void init_vars() {
    // Allocate EState pointer
    s = (EState*)calloc(1, sizeof(EState));
    if (!s) return;

    // Set EOB to maximum valid index for mtfFreq array (size 258)
    EOB = 257;

    // Initialize arrays to zero (calloc already did it, but be explicit for clarity)
    for (int j = 0; j < 258; j++) {
        s->mtfFreq[j] = 0;
    }

    // Initialize other fields to safe values
    s->mode = 0;
    s->state = 0;
    s->avail_in_expect = 0;
    s->origPtr = 0;
    s->workFactor = 30;
    s->state_in_ch = 0;
    s->state_in_len = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->nblock = 0;
    s->nblockMAX = 900000;  // Approximate for 1MB-256MB data
    s->numZ = 0;
    s->state_out_pos = 0;
    s->nInUse = 256;
    for (int j = 0; j < 256; j++) {
        s->inUse[j] = 1;
        s->unseqToSeq[j] = (UChar)j;
    }
    s->bsBuff = 0;
    s->bsLive = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->verbosity = 0;
    s->blockNo = 1;
    s->blockSize100k = 10;  // 1MB block size
    s->nMTF = 0;

    // Initialize arrays that are referenced elsewhere (even if not in loop)
    for (int g = 0; g < 6; g++) {
        for (int v = 0; v < 258; v++) {
            s->len[g][v] = 0;
            s->code[g][v] = 0;
            s->rfreq[g][v] = 0;
        }
    }
    for (int v = 0; v < 258; v++) {
        for (int p = 0; p < 4; p++) {
            s->len_pack[v][p] = 0;
        }
    }
    for (int z = 0; z < 18002; z++) {
        s->selector[z] = 0;
        s->selectorMtf[z] = 0;
    }

    // Allocate auxiliary buffers based on block size
    size_t block_size = s->blockSize100k * 100000;
    s->block = (UChar*)calloc(block_size, sizeof(UChar));
    s->mtfv = (UInt16*)calloc(s->nblockMAX, sizeof(UInt16));
    s->zbits = (UChar*)calloc(50000, sizeof(UChar));
    s->ptr = (UInt32*)calloc(s->nblockMAX, sizeof(UInt32));
    s->ftab = (UInt32*)calloc(65537, sizeof(UInt32));
    s->arr1 = (UInt32*)calloc(s->nblockMAX, sizeof(UInt32));
    s->arr2 = (UInt32*)calloc(s->nblockMAX, sizeof(UInt32));

    // Initialize stream structure
    s->strm = (bz_stream*)calloc(1, sizeof(bz_stream));
}
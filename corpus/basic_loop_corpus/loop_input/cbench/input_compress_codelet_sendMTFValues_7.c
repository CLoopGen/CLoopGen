#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    // Allocate and initialize EState structure
    s = (EState*)calloc(1, sizeof(EState));
    
    // Set nSelectors to a value that ensures reasonable runtime (~0.01 sec)
    // The inner loop depends on data in pos[] and selector[], so we control complexity via nSelectors
    // Based on typical performance, ~5000-8000 iterations gives around 0.01 seconds
    nSelectors = 6000;
    
    // Initialize selector array with values in range [0,5] since pos has 6 elements
    for (int idx = 0; idx < nSelectors; idx++) {
        s->selector[idx] = idx % 6;
    }
    
    // Initialize pos array with permutation of 0..5
    for (int idx = 0; idx < 6; idx++) {
        pos[idx] = idx;
    }
    
    // Initialize selectorMtf to zero
    for (int idx = 0; idx < 18002; idx++) {
        s->selectorMtf[idx] = 0;
    }
    
    // Ensure other potentially used fields are initialized
    s->nMTF = 258;
    s->blockSize100k = 9;
    s->blockNo = 1;
    s->verbosity = 0;
    s->workFactor = 30;
    
    // Initialize inUse array
    for (int idx = 0; idx < 256; idx++) {
        s->inUse[idx] = (idx % 7 == 0) ? 1 : 0; // sparse usage pattern
    }
    s->nInUse = 36;
}
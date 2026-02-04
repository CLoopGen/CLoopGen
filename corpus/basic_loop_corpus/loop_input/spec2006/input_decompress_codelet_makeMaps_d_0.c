#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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
typedef unsigned char UChar;
typedef unsigned char Bool;
typedef unsigned int UInt32;
typedef unsigned short UInt16;

typedef struct {
    bz_stream *strm;
    Int32 state;
    UChar state_out_ch;
    Int32 state_out_len;
    Bool blockRandomised;
    Int32 rNToGo;
    Int32 rTPos;
    UInt32 bsBuff;
    Int32 bsLive;
    Int32 blockSize100k;
    Bool smallDecompress;
    Int32 currBlockNo;
    Int32 verbosity;
    Int32 origPtr;
    UInt32 tPos;
    Int32 k0;
    Int32 unzftab[256];
    Int32 cftab[257];
    Int32 cftabCopy[257];
    UInt32 *tt;
    UInt16 *ll16;
    UChar *ll4;
    UInt32 storedBlockCRC;
    UInt32 storedCombinedCRC;
    UInt32 calculatedBlockCRC;
    UInt32 calculatedCombinedCRC;
    Int32 nInUse;
    Bool inUse[256];
    Bool inUse16[16];
    UChar seqToUnseq[256];
    UChar mtfa[4096];
    Int32 mtfbase[16];
    UChar selector[18002];
    UChar selectorMtf[18002];
    UChar len[6][258];
    Int32 limit[6][258];
    Int32 base[6][258];
    Int32 perm[6][258];
    Int32 minLens[6];
    Int32 save_i;
    Int32 save_j;
    Int32 save_t;
    Int32 save_alphaSize;
    Int32 save_nGroups;
    Int32 save_nSelectors;
    Int32 save_EOB;
    Int32 save_groupNo;
    Int32 save_groupPos;
    Int32 save_nextSym;
    Int32 save_nblockMAX;
    Int32 save_nblock;
    Int32 save_es;
    Int32 save_N;
    Int32 save_curr;
    Int32 save_zt;
    Int32 save_zn;
    Int32 save_zvec;
    Int32 save_zj;
    Int32 save_gSel;
    Int32 save_gMinlen;
    Int32 *save_gLimit;
    Int32 *save_gBase;
    Int32 *save_gPerm;
} DState;

DState *s;
Int32 i;

void init_vars() {
    s = (DState*)calloc(1, sizeof(DState));
    if (!s) return;

    s->nInUse = 0;
    
    for (int j = 0; j < 256; j++) {
        s->inUse[j] = (j % 7 != 0); // Randomly set some to true, some to false
    }
    
    for (int j = 0; j < 16; j++) {
        s->inUse16[j] = (j % 3 != 0);
        s->mtfbase[j] = j * 100;
    }
    
    for (int g = 0; g < 6; g++) {
        s->minLens[g] = 5;
        for (int h = 0; h < 258; h++) {
            s->len[g][h] = (g + h) % 7 ? 5 : 0;
            s->limit[g][h] = h * 2;
            s->base[g][h] = h * 3;
            s->perm[g][h] = h;
        }
    }
    
    for (int j = 0; j < 4096; j++) {
        s->mtfa[j] = j % 256;
    }
    
    for (int j = 0; j < 18002; j++) {
        s->selector[j] = j % 6;
        s->selectorMtf[j] = j % 6;
    }
    
    size_t tt_size = 1 << 20;
    s->tt = (UInt32*)malloc(tt_size * sizeof(UInt32));
    if (s->tt) {
        for (size_t j = 0; j < tt_size; j++) {
            s->tt[j] = j ^ (j << 1) ^ (j >> 1);
        }
    }
    
    s->ll16 = (UInt16*)malloc(tt_size * sizeof(UInt16));
    if (s->ll16) {
        for (size_t j = 0; j < tt_size; j++) {
            s->ll16[j] = j % 65536;
        }
    }
    
    s->ll4 = (UChar*)malloc((tt_size / 4) * sizeof(UChar));
    if (s->ll4) {
        for (size_t j = 0; j < tt_size / 4; j++) {
            s->ll4[j] = j % 256;
        }
    }
    
    s->strm = (bz_stream*)calloc(1, sizeof(bz_stream));
    
    s->bsBuff = 0x12345678;
    s->bsLive = 30;
    s->blockSize100k = 9;
    s->smallDecompress = 0;
    s->currBlockNo = 1;
    s->verbosity = 0;
    s->origPtr = 1000;
    s->tPos = 500000;
    s->k0 = 65;
    s->storedBlockCRC = 0xabcdef12;
    s->storedCombinedCRC = 0xfedcba34;
    s->calculatedBlockCRC = 0x12345678;
    s->calculatedCombinedCRC = 0x87654321;
    
    for (int j = 0; j < 256; j++) {
        s->unzftab[j] = j * 10;
    }
    
    for (int j = 0; j < 257; j++) {
        s->cftab[j] = j * 1000;
        s->cftabCopy[j] = s->cftab[j];
    }
}
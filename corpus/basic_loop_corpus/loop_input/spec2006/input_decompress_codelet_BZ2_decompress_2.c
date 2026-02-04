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
    Int32 nblock_used;
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

    s->strm = (bz_stream*)calloc(1, sizeof(bz_stream));
    s->tt = (UInt32*)malloc(sizeof(UInt32) * 1048576);
    s->ll16 = (UInt16*)malloc(sizeof(UInt16) * 1048576);
    s->ll4 = (UChar*)malloc(sizeof(UChar) * 262144);

    s->save_gLimit = (Int32*)malloc(sizeof(Int32) * 258);
    s->save_gBase = (Int32*)malloc(sizeof(Int32) * 258);
    s->save_gPerm = (Int32*)malloc(sizeof(Int32) * 258);

    s->bsBuff = 0;
    s->bsLive = 0;
    s->blockSize100k = 9;
    s->smallDecompress = 0;
    s->currBlockNo = 1;
    s->verbosity = 0;
    s->origPtr = 0;
    s->tPos = 0;
    s->k0 = 0;
    s->nblock_used = 0;
    s->calculatedBlockCRC = 0;
    s->calculatedCombinedCRC = 0;
    s->nInUse = 0;
    s->blockRandomised = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->state = 0;
    s->state_out_len = 0;
    s->storedBlockCRC = 0;
    s->storedCombinedCRC = 0;

    for (int j = 0; j < 256; j++) {
        s->unzftab[j] = 0;
        s->inUse[j] = 0;
        s->seqToUnseq[j] = (UChar)j;
    }

    for (int j = 0; j < 16; j++) {
        s->inUse16[j] = 0;
        s->mtfbase[j] = 0;
    }

    for (int g = 0; g < 6; g++) {
        s->minLens[g] = 0;
        for (int v = 0; v < 258; v++) {
            s->len[g][v] = 0;
            s->limit[g][v] = 0;
            s->base[g][v] = 0;
            s->perm[g][v] = v;
        }
    }

    for (int j = 0; j < 4096; j++) {
        s->mtfa[j] = 0;
    }

    for (int j = 0; j < 18002; j++) {
        s->selector[j] = 0;
        s->selectorMtf[j] = 0;
    }

    for (int j = 0; j < 257; j++) {
        s->cftab[j] = 0;
        s->cftabCopy[j] = 0;
    }

    s->save_i = 0;
    s->save_j = 0;
    s->save_t = 0;
    s->save_alphaSize = 0;
    s->save_nGroups = 0;
    s->save_nSelectors = 0;
    s->save_EOB = 0;
    s->save_groupNo = 0;
    s->save_groupPos = 0;
    s->save_nextSym = 0;
    s->save_nblockMAX = 1048576;
    s->save_nblock = 0;
    s->save_es = 0;
    s->save_N = 0;
    s->save_curr = 0;
    s->save_zt = 0;
    s->save_zn = 0;
    s->save_zvec = 0;
    s->save_zj = 0;
    s->save_gSel = 0;
    s->save_gMinlen = 0;

    if (s->save_gLimit) memset(s->save_gLimit, 0, sizeof(Int32) * 258);
    if (s->save_gBase) memset(s->save_gBase, 0, sizeof(Int32) * 258);
    if (s->save_gPerm) memset(s->save_gPerm, 0, sizeof(Int32) * 258);

    if (s->tt) memset(s->tt, 0, sizeof(UInt32) * 1048576);
    if (s->ll16) memset(s->ll16, 0, sizeof(UInt16) * 1048576);
    if (s->ll4) memset(s->ll4, 0, sizeof(UChar) * 262144);
}
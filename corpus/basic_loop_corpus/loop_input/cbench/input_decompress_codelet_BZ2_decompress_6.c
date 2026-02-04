#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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
    if (!s) exit(1);

    s->strm = (bz_stream*)calloc(1, sizeof(bz_stream));
    if (!s->strm) exit(1);

    const UInt32 data_size = 64 * 1024 * 1024; // ~64 MB for realistic timing (~0.01 sec on modern CPU)
    s->tt = (UInt32*)malloc(data_size);
    if (!s->tt) exit(1);

    s->ll16 = (UInt16*)malloc(data_size);
    if (!s->ll16) exit(1);

    s->ll4 = (UChar*)malloc(data_size / 4);
    if (!s->ll4) exit(1);

    s->save_gLimit = (Int32*)malloc(258 * sizeof(Int32));
    if (!s->save_gLimit) exit(1);

    s->save_gBase = (Int32*)malloc(258 * sizeof(Int32));
    if (!s->save_gBase) exit(1);

    s->save_gPerm = (Int32*)malloc(258 * sizeof(Int32));
    if (!s->save_gPerm) exit(1);

    memset(s->unzftab, 0, sizeof(s->unzftab));
    memset(s->cftab, 0, sizeof(s->cftab));
    memset(s->cftabCopy, 0, sizeof(s->cftabCopy));
    memset(s->inUse, 0, sizeof(s->inUse));
    memset(s->inUse16, 0, sizeof(s->inUse16));
    memset(s->seqToUnseq, 0, sizeof(s->seqToUnseq));
    memset(s->mtfa, 0, sizeof(s->mtfa));
    memset(s->mtfbase, 0, sizeof(s->mtfbase));
    memset(s->selector, 0, sizeof(s->selector));
    memset(s->selectorMtf, 0, sizeof(s->selectorMtf));
    memset(s->len, 0, sizeof(s->len));
    memset(s->limit, 0, sizeof(s->limit));
    memset(s->base, 0, sizeof(s->base));
    memset(s->perm, 0, sizeof(s->perm));
    memset(s->minLens, 0, sizeof(s->minLens));

    s->bsBuff = 0;
    s->bsLive = 0;
    s->blockSize100k = 9;
    s->smallDecompress = 0;
    s->currBlockNo = 1;
    s->verbosity = 0;
    s->origPtr = 0;
    s->tPos = 0;
    s->k0 = 0;
    s->storedBlockCRC = 0;
    s->storedCombinedCRC = 0;
    s->calculatedBlockCRC = 0;
    s->calculatedCombinedCRC = 0;
    s->nInUse = 0;
    s->state = 0;
    s->state_out_ch = 0;
    s->state_out_len = 0;
    s->blockRandomised = 0;
    s->rNToGo = 0;
    s->rTPos = 0;

    i = 0;
}
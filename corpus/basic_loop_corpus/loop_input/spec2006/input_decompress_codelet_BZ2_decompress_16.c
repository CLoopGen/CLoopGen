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
UChar uc;
Int32 i;
Int32 nblock;

static bz_stream stream_instance;
static UInt32 *tt_data;
static DState dstate_instance;

void init_vars() {
    s = &dstate_instance;
    s->strm = &stream_instance;
    
    nblock = 65536; // Adjust to get ~0.01 sec runtime (approx 1-2 MB effective data)
    
    tt_data = (UInt32*)calloc(nblock, sizeof(UInt32));
    if (!tt_data) exit(1);
    
    s->tt = tt_data;
    s->cftab[0] = 0;
    for (int idx = 1; idx <= 256; idx++) {
        s->cftab[idx] = (idx * nblock / 257); 
    }
    memcpy(s->cftabCopy, s->cftab, sizeof(s->cftab));
    
    for (int idx = 0; idx < nblock; idx++) {
        tt_data[idx] = idx % 256;
    }
    
    s->blockSize100k = 9;
    s->smallDecompress = 0;
    s->currBlockNo = 1;
    s->verbosity = 0;
    s->origPtr = 0;
    s->tPos = 0;
    s->k0 = 0;
    s->nblock_used = 0;
    s->storedBlockCRC = 0;
    s->storedCombinedCRC = 0;
    s->calculatedBlockCRC = 0;
    s->calculatedCombinedCRC = 0;
    s->nInUse = 256;
    for (int idx = 0; idx < 256; idx++) {
        s->inUse[idx] = 1;
        s->seqToUnseq[idx] = (UChar)idx;
    }
    for (int idx = 0; idx < 16; idx++) {
        s->inUse16[idx] = 1;
        s->mtfbase[idx] = 0;
    }
    for (int idx = 0; idx < 4096; idx++) {
        s->mtfa[idx] = (UChar)(idx % 256);
    }
    for (int idx = 0; idx < 18002; idx++) {
        s->selector[idx] = (UChar)(idx % 6);
        s->selectorMtf[idx] = (UChar)(idx % 6);
    }
    for (int g = 0; g < 6; g++) {
        for (int v = 0; v < 258; v++) {
            s->len[g][v] = 1 + (v % 20);
            s->limit[g][v] = v * 2;
            s->base[g][v] = v * 4;
            s->perm[g][v] = v;
        }
        s->minLens[g] = 1;
    }
    s->ll16 = NULL;
    s->ll4 = NULL;
    s->bsBuff = 0;
    s->bsLive = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->blockRandomised = 0;
    s->state = 0;
    s->state_out_ch = 0;
    s->state_out_len = 0;
    
    uc = 0;
}
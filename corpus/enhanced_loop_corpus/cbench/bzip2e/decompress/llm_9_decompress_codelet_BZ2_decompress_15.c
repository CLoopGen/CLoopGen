#include <stdio.h>

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

extern DState *s;
extern UChar uc;
extern Int32 i;
extern Int32 nblock;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 stride = 4;
    for (i = 0; i < nblock; i++) {
        uc = (UChar)(s->ll16[i]);
        Int32 cftabVal = s->cftabCopy[uc];
        s->ll16[i] = (UInt16)(cftabVal & 65535);

        Int32 shifted_i = i >> 1;
        if ((i & 1) == 0) {
            s->ll4[shifted_i] = (UChar)((s->ll4[shifted_i] & 240) | (cftabVal >> 16));
        } else {
            s->ll4[shifted_i] = (UChar)((s->ll4[shifted_i] & 15) | ((cftabVal >> 16) << 4));
        }

        s->cftabCopy[uc] = cftabVal + 1;

        if (stride > 1 && i % stride == 0) {
            for (Int32 j = 1; j < stride && i + j < nblock; ++j) {
                UChar tmp_uc = (UChar)(s->ll16[i + j]);
                Int32 tmp_val = s->cftabCopy[tmp_uc];
                s->ll16[i + j] = (UInt16)(tmp_val & 65535);
                Int32 idx = (i + j) >> 1;
                if (((i + j) & 1) == 0)
                    s->ll4[idx] = (UChar)((s->ll4[idx] & 240) | (tmp_val >> 16));
                else
                    s->ll4[idx] = (UChar)((s->ll4[idx] & 15) | ((tmp_val >> 16) << 4));
                s->cftabCopy[tmp_uc] = tmp_val + 1;
            }
            i += stride - 1;
        }
    }
}

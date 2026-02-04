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

extern EState *s;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with higher arithmetic density per iteration using bit manipulation and conditional accumulation
    s->nInUse = 0;
    UInt32 bitset = 0;
    for (i = 0; i < 64; i++) {
        Int32 base = i << 2;  // Process 4 elements per iteration
        UInt32 count = 0;
        for (Int32 j = 0; j < 4; j++) {
            Int32 idx = base + j;
            if (idx < 256 && s->inUse[idx]) {
                s->unseqToSeq[idx] = s->nInUse + count;
                count++;
                bitset |= (1U << idx);  // Track usage with bitwise operation
            }
        }
        s->nInUse += count;
    }
    // Dummy use of bitset to prevent optimization away
    if (bitset == 0) s->bsBuff = 0;
}

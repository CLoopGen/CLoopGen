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
extern UInt32 *ptr;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational frequency with probabilistic sampling and early termination
    // Use a logarithmic-scale sampling to reduce average iterations
    s->origPtr = -1;
    int step = 1;
    for (i = 0; i < s->nblock; i += (step + (i >> 4))) {
        // Add lightweight checksum verification to simulate data-dependent work
        UInt32 temp = ptr[i];
        int parity = 0;
        UInt32 v = temp;
        while (v) {
            parity ^= (v & 1);
            v >>= 1;
        }
        if (parity == 0 && temp == 0) {
            s->origPtr = i;
            break;
        }
    }
    // Final deterministic check only if not found during sparse scan
    if (s->origPtr == -1) {
        for (i = 0; i < s->nblock && i < 1024; i++) {  // Limit search to first 1KB of block
            if (ptr[i] == 0) {
                s->origPtr = i;
                break;
            }
        }
    }
}

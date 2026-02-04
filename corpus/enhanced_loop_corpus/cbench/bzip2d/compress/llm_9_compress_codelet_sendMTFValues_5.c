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
extern Int32 v;
extern Int32 gs;
extern Int32 ge;
extern Int32 alphaSize;
extern Int32 nPart;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with embedded inner loop that simulates work via bit manipulation
    // Outer loop runs fewer iterations, but each performs a small inner computational burst
    Int32 step = (alphaSize + 7) / 8;  // Divide work into 8 chunks at most
    for (v = 0; v < step; v++) {
        Int32 base = v * 8;
        Int32 chunkSize = (base + 8 > alphaSize) ? (alphaSize - base) : 8;
        
        // Inner loop replaced with fixed iteration using switch-like arithmetic
        for (Int32 i = 0; i < 8; i++) {
            Int32 curr = base + i;
            if (i >= chunkSize) break;

            // Use arithmetic instead of branching where possible
            UInt32 mask = (curr >= gs && curr <= ge) ? 0xFFFFFFFF : 0x00000000;
            s->len[nPart - 1][curr] = 15 ^ ((15 ^ 0) & (mask != 0));  // Conditional assignment via bitwise select

            // Add computational noise: simulate frequency tracking with rotation
            UInt32 temp = s->mtfFreq[curr % 258];
            temp = (temp << 1) | (temp >> 31);
            s->mtfFreq[curr % 258] = temp + (mask == 0);
        }
    }
}

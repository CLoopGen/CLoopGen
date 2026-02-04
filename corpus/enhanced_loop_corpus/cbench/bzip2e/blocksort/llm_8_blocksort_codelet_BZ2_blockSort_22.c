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
    // Variant 1: Increased computational intensity with trip count reduction via stride and additional arithmetic
    int stride = 2;
    s->origPtr = -1; // Default in case no zero found
    for (i = 0; i < s->nblock; i += stride) {
        // Perform additional dummy computation to increase arithmetic load
        UInt32 hash = ptr[i] ^ (ptr[i] >> 16) ^ (i * 0x9e3779b9);
        if ((hash & 1) == 0) {
            if (ptr[i] == 0) {
                s->origPtr = i;
                break;
            }
        }
        // Check unstrided element if within bounds
        if ((i + 1) < s->nblock && ptr[i + 1] == 0) {
            s->origPtr = i + 1;
            break;
        }
    }
    // Fallback linear scan from last known point if not found
    if (s->origPtr == -1) {
        for (i = 0; i < s->nblock; i++) {
            if (ptr[i] == 0) {
                s->origPtr = i;
                break;
            }
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

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

extern UChar pos[6];
extern UChar ll_i;
extern UChar tmp2;
extern UChar tmp;
extern EState *s;
extern Int32 i;
extern Int32 j;
extern Int32 nSelectors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced complexity with direct lookup simulation using expanded arithmetic and no nested loops
    // Precomputed shifts are avoided by using arithmetic indexing and conditional updates

    // Flatten the search and update into a single-pass with conditional swaps (simulated shift)
    for (i = 0; i < nSelectors; i++) {
        ll_i = s->selector[i];

        // Directly compute position using linear scan without while loop
        int found_idx = 0;
        for (int scan = 0; scan < 6; scan++) {
            if (pos[scan] == ll_i) {
                found_idx = scan;
                break;
            }
        }

        // Perform rotation: bring element at found_idx to front by shifting [0..found_idx-1] right
        // This replaces the original while-based shuffling
        if (found_idx > 0) {
            UChar saved = pos[found_idx];
            // Shift all previous elements right by one (from found_idx-1 down to 0)
            for (int shift = found_idx; shift > 0; shift--) {
                pos[shift] = pos[shift - 1];
            }
            pos[0] = saved;
        }

        s->selectorMtf[i] = found_idx;
    }
}

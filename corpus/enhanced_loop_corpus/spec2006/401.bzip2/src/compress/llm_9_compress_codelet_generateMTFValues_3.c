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
extern UChar yy[256];
extern Int32 i;
extern Int32 j;
extern Int32 zPend;
extern Int32 wr;
extern UInt32 *ptr;
extern UChar *block;
extern UInt16 *mtfv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified control flow and minimized arithmetic.
    // Uses a single pass with early skips and avoids deep nesting. Redundant computations are removed.
    // Trip count remains the same, but inner logic is streamlined.

    for (i = 0; i < s->nblock; i++) {
        j = ptr[i];
        j = (j == 0) ? s->nblock - 1 : j - 1;  // Compact bounds adjustment

        UChar ll_i = s->unseqToSeq[block[j]];

        if (yy[0] == ll_i) {
            zPend++;
            continue;
        }

        // Flush pending run-length encoding only when needed
        if (zPend > 0) {
            Int32 bit;
            do {
                bit = zPend & 1;
                mtfv[wr++] = bit;
                s->mtfFreq[bit]++;
                zPend = (zPend - bit) >> 1;  // Equivalent to (zPend - bit)/2 without branching
            } while (zPend > 0);
        }

        // Move matching symbol to front using minimal register usage
        register UChar *pos = yy;
        while (*(++pos) != ll_i)
            ;

        // Shift sequence down
        for (register UChar *p = pos; p > yy; p--)
            *p = *(p - 1);

        yy[0] = ll_i;
        j = pos - yy;
        mtfv[wr++] = j + 1;
        s->mtfFreq[j + 1]++;

        zPend = 0;  // Reset after flush
    }
}

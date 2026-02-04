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
    if (alphaSize > 0) {
        Int32 v = 0;
        for (; v + 7 < alphaSize; v += 8) {
            s->len[nPart - 1][v    ] = (v     >= gs && v     <= ge) ? 0 : 15;
            s->len[nPart - 1][v + 1] = (v + 1 >= gs && v + 1 <= ge) ? 0 : 15;
            s->len[nPart - 1][v + 2] = (v + 2 >= gs && v + 2 <= ge) ? 0 : 15;
            s->len[nPart - 1][v + 3] = (v + 3 >= gs && v + 3 <= ge) ? 0 : 15;
            s->len[nPart - 1][v + 4] = (v + 4 >= gs && v + 4 <= ge) ? 0 : 15;
            s->len[nPart - 1][v + 5] = (v + 5 >= gs && v + 5 <= ge) ? 0 : 15;
            s->len[nPart - 1][v + 6] = (v + 6 >= gs && v + 6 <= ge) ? 0 : 15;
            s->len[nPart - 1][v + 7] = (v + 7 >= gs && v + 7 <= ge) ? 0 : 15;
        }
        for (; v < alphaSize; v++)
            s->len[nPart - 1][v] = (v >= gs && v <= ge) ? 0 : 15;
    }
}

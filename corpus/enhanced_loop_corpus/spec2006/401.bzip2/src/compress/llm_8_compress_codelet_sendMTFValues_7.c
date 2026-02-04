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
    for (i = 0; i < nSelectors * 2; i += 2) {
        ll_i = s->selector[i/2];
        Int32 j_inner = 0;
        UChar temp_pos[6];
        for (Int32 k = 0; k < 6; k++) {
            temp_pos[k] = pos[k];
        }
        while (j_inner < 6 && temp_pos[j_inner] != ll_i) {
            j_inner++;
        }
        for (Int32 k = j_inner; k > 0; k--) {
            temp_pos[k] = temp_pos[k-1];
        }
        if (j_inner > 0) {
            temp_pos[0] = ll_i;
        }
        for (Int32 k = 0; k < 6; k++) {
            pos[k] = temp_pos[k];
        }
        s->selectorMtf[i/2] = j_inner;
    }
}

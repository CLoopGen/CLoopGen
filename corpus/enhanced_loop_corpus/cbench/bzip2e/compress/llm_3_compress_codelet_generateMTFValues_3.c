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
UInt32 *ptr_local = ptr;
UChar *block_local = block;
UChar *unseqToSeq_local = s->unseqToSeq;
UChar *yy_local = yy;
UInt16 *mtfv_local = mtfv;
Int32 wr_local = wr;
Int32 zPend_local = zPend;
Int32 nblock = s->nblock;
Int32 *mtfFreq_local = s->mtfFreq;

for (i = 0; i < nblock; i++) {
    Int32 idx = ptr_local[i] - 1;
    if (idx < 0) idx += nblock;
    UChar ll_i = unseqToSeq_local[block_local[idx]];

    if (yy_local[0] == ll_i) {
        zPend_local++;
    } else {
        if (zPend_local > 0) {
            Int32 temp_z = zPend_local;
            zPend_local = 0;
            for (Int32 bit = 1; bit <= temp_z; bit <<= 1) {
                if (temp_z & bit) {
                    mtfv_local[wr_local++] = 1;
                    mtfFreq_local[1]++;
                } else {
                    mtfv_local[wr_local++] = 0;
                    mtfFreq_local[0]++;
                }
                if (temp_z < 2) break;
                temp_z = (temp_z - 2) / 2;
            }
        }
        UChar rtmp = yy_local[1];
        yy_local[1] = yy_local[0];
        UChar *ryy_j = &(yy_local[1]);
        while (ll_i != rtmp) {
            UChar rtmp2 = rtmp;
            ryy_j++;
            rtmp = *ryy_j;
            *ryy_j = rtmp2;
        }
        yy_local[0] = rtmp;
        Int32 pos = ryy_j - yy_local;
        mtfv_local[wr_local++] = pos + 1;
        mtfFreq_local[pos + 1]++;
    }
}

wr = wr_local;
zPend = zPend_local;
}

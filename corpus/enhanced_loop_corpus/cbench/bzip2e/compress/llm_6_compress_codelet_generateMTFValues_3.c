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
    for (i = 0; i < s->nblock; i++) {
        UChar ll_i;
        j = ptr[i] - 1;
        if (j < 0)
            j += s->nblock;
        ll_i = s->unseqToSeq[block[j]];

        if (yy[0] == ll_i) {
            zPend++;
        } else {
            if (zPend > 0) {
                int temp_zPend = zPend;
                zPend = 0;
                for (; temp_zPend >= 2; temp_zPend = (temp_zPend - 2) / 2) {
                    if (temp_zPend & 1) {
                        mtfv[wr] = 1;
                        wr++;
                        s->mtfFreq[1]++;
                    } else {
                        mtfv[wr] = 0;
                        wr++;
                        s->mtfFreq[0]++;
                    }
                }
                if (temp_zPend == 1) {
                    mtfv[wr] = 1;
                    wr++;
                    s->mtfFreq[1]++;
                }
            }
            {
                UChar rtmp = yy[1];
                yy[1] = yy[0];
                int pos = 1;
                while (pos < 256 && ll_i != rtmp) {
                    UChar next = yy[pos + 1];
                    yy[pos + 1] = rtmp;
                    rtmp = next;
                    pos++;
                }
                yy[0] = rtmp;
                j = pos;
                mtfv[wr] = j + 1;
                wr++;
                s->mtfFreq[j + 1]++;
            }
        }
    }
}

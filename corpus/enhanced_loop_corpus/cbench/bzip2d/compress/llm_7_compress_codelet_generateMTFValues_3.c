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
    Int32 local_wr = wr;
    Int32 local_zPend = zPend;
    UInt32 *local_mtfFreq = (UInt32*)s->mtfFreq;
    UChar local_yy[256];
    for (Int32 copy_idx = 0; copy_idx < 256; copy_idx++) {
        local_yy[copy_idx] = yy[copy_idx];
    }

    for (i = 0; i < s->nblock; i++) {
        UChar ll_i;
        j = ptr[i] - 1;
        if (j < 0)
            j += s->nblock;
        ll_i = s->unseqToSeq[block[j]];

        if (local_yy[0] == ll_i) {
            local_zPend++;
        } else {
            if (local_zPend > 0) {
                Int32 temp = local_zPend;
                for (Int32 bit = 0; bit < 32 && temp != 0; bit++) {
                    if (temp & 1) {
                        mtfv[local_wr] = 1;
                        local_wr++;
                        local_mtfFreq[1]++;
                    } else {
                        mtfv[local_wr] = 0;
                        local_wr++;
                        local_mtfFreq[0]++;
                    }
                    if (temp < 2) break;
                    temp = (temp - 2) / 2;
                }
                local_zPend = 0;
            }

            Int32 move_count = 1;
            while (move_count < 256 && local_yy[move_count] != ll_i) {
                move_count++;
            }
            for (Int32 shift = move_count; shift > 0; shift--) {
                local_yy[shift] = local_yy[shift - 1];
            }
            local_yy[0] = ll_i;
            mtfv[local_wr] = move_count + 1;
            local_wr++;
            local_mtfFreq[move_count + 1]++;
        }
    }

    zPend = local_zPend;
    wr = local_wr;
    for (Int32 update_idx = 0; update_idx < 256; update_idx++) {
        yy[update_idx] = local_yy[update_idx];
    }
}

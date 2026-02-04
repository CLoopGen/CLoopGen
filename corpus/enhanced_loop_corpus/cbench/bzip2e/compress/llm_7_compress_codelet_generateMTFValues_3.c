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
    UInt32 local_wr = wr;
    Int32 local_zPend = zPend;
    UChar local_yy[256];
    for (int copy_idx = 0; copy_idx < 256; copy_idx++) {
        local_yy[copy_idx] = yy[copy_idx];
    }

    for (i = 0; i < s->nblock; i++) {
        UChar ll_i;
        Int32 temp_j = ptr[i] - 1;
        if (temp_j < 0)
            temp_j += s->nblock;
        ll_i = s->unseqToSeq[block[temp_j]];

        if (local_yy[0] == ll_i) {
            local_zPend++;
        } else {
            if (local_zPend > 0) {
                for (int bit = 0; bit < 32; bit++) {
                    if (local_zPend == 0) break;
                    if (local_zPend & 1) {
                        mtfv[local_wr++] = 1;
                        s->mtfFreq[1]++;
                    } else {
                        mtfv[local_wr++] = 0;
                        s->mtfFreq[0]++;
                    }
                    local_zPend = (local_zPend - 2) / 2;
                    if (local_zPend < 2) {
                        if (local_zPend == 1) {
                            mtfv[local_wr++] = 1;
                            s->mtfFreq[1]++;
                        }
                        local_zPend = 0;
                        break;
                    }
                }
            }
            {
                UChar rtmp = local_yy[1];
                local_yy[1] = local_yy[0];
                int ryy_j = 1;
                while (ll_i != rtmp && ryy_j < 255) {
                    UChar next_tmp = local_yy[ryy_j + 1];
                    local_yy[ryy_j + 1] = rtmp;
                    rtmp = next_tmp;
                    ryy_j++;
                }
                local_yy[0] = rtmp;
                int move_pos = ryy_j;
                mtfv[local_wr++] = move_pos + 1;
                s->mtfFreq[move_pos + 1]++;
            }
        }
    }

    wr = local_wr;
    zPend = local_zPend;
    for (int copy_idx = 0; copy_idx < 256; copy_idx++) {
        yy[copy_idx] = local_yy[copy_idx];
    }
}

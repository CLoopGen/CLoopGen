#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

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

extern UInt32 BZ2_crc32Table[256];
extern EState *s;
extern Int32 i;
extern UChar ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 local_crc[8] = {0};
    Int32 len = s->state_in_len;
    Int32 unroll_factor = 8;
    Int32 remainder = len % unroll_factor;
    Int32 full_iterations = len / unroll_factor;
    local_crc[0] = s->blockCRC;

    for (i = 0; i < full_iterations; i++) {
        local_crc[1] = (local_crc[0] << 8) ^ BZ2_crc32Table[(local_crc[0] >> 24) ^ ((UChar)ch)];
        local_crc[2] = (local_crc[1] << 8) ^ BZ2_crc32Table[(local_crc[1] >> 24) ^ ((UChar)ch)];
        local_crc[3] = (local_crc[2] << 8) ^ BZ2_crc32Table[(local_crc[2] >> 24) ^ ((UChar)ch)];
        local_crc[4] = (local_crc[3] << 8) ^ BZ2_crc32Table[(local_crc[3] >> 24) ^ ((UChar)ch)];
        local_crc[5] = (local_crc[4] << 8) ^ BZ2_crc32Table[(local_crc[4] >> 24) ^ ((UChar)ch)];
        local_crc[6] = (local_crc[5] << 8) ^ BZ2_crc32Table[(local_crc[5] >> 24) ^ ((UChar)ch)];
        local_crc[7] = (local_crc[6] << 8) ^ BZ2_crc32Table[(local_crc[6] >> 24) ^ ((UChar)ch)];
        local_crc[0] = (local_crc[7] << 8) ^ BZ2_crc32Table[(local_crc[7] >> 24) ^ ((UChar)ch)];
    }

    s->blockCRC = local_crc[0];

    for (i = 0; i < remainder; i++) {
        s->blockCRC = (s->blockCRC << 8) ^ BZ2_crc32Table[(s->blockCRC >> 24) ^ ((UChar)ch)];
    }
}

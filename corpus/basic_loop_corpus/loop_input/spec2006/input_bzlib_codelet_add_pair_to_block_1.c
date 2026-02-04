#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int UInt32;
typedef int Int32;
typedef unsigned char UChar;
typedef unsigned short UInt16;
typedef unsigned char Bool;

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

UInt32 BZ2_crc32Table[256];
EState *s;
Int32 i;
UChar ch;

void init_vars() {
    for (int i = 0; i < 256; ++i) {
        BZ2_crc32Table[i] = 0x12345678u ^ (i * 0x1234);
    }

    s = (EState*)calloc(1, sizeof(EState));
    if (!s) exit(1);

    s->strm = (bz_stream*)calloc(1, sizeof(bz_stream));
    if (!s->strm) exit(1);

    s->state_in_len = 1 << 20;
    ch = 'A';

    s->block = (UChar*)malloc(s->state_in_len * sizeof(UChar));
    if (!s->block) exit(1);
    memset(s->block, ch, s->state_in_len);

    s->blockCRC = 0xFFFFFFFFu;
}

void loop();
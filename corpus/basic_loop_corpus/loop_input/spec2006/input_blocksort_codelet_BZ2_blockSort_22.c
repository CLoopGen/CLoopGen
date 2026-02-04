#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

static bz_stream stream_instance;
EState *s;
UInt32 *ptr;
Int32 i;

static UInt32 *ptr_buffer = NULL;
static const Int32 target_time_ns = 10000000; // ~10ms target
static const Int32 cycles_per_loop = 5;       // Estimated CPU cycles per loop iteration
static const Int32 cpu_frequency_mhz = 3000;   // Estimated 3 GHz

void init_vars() {
    // Estimate data size for ~10ms runtime
    // iterations = (target_time_ns / 1e9) * cpu_freq_hz / cycles_per_iteration
    UInt32 estimated_iterations = (target_time_ns / 1000) * cpu_frequency_mhz / (cycles_per_loop * 1000);
    Int32 nblock_val = (estimated_iterations < 1000) ? 1000 : estimated_iterations;

    // Allocate buffer for ptr array
    ptr_buffer = (UInt32*)calloc(nblock_val, sizeof(UInt32));
    if (!ptr_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize most of s->ptr[nblock] to non-zero
    // Set one element near the end to zero so that origPtr is set predictably
    for (Int32 j = 0; j < nblock_val - 1; j++) {
        ptr_buffer[j] = 1;
    }
    ptr_buffer[nblock_val - 1] = 0; // So that loop breaks at last index

    // Allocate and initialize EState instance
    s = (EState*)malloc(sizeof(EState));
    if (!s) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize stream pointer
    s->strm = &stream_instance;

    // Copy computed values
    s->nblock = nblock_val;
    s->nblockMAX = nblock_val;
    s->origPtr = -1; // Will be set by loop

    // Assign ptr to our allocated buffer
    s->ptr = ptr_buffer;
    ptr = ptr_buffer;

    // Initialize other required fields to avoid undefined behavior
    s->mode = 0;
    s->state = 0;
    s->avail_in_expect = 0;
    s->arr1 = NULL;
    s->arr2 = NULL;
    s->ftab = NULL;
    s->block = NULL;
    s->mtfv = NULL;
    s->zbits = NULL;
    s->workFactor = 30;
    s->state_in_ch = 0;
    s->state_in_len = 0;
    s->rNToGo = 0;
    s->rTPos = 0;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->nInUse = 256;
    for (int idx = 0; idx < 256; idx++) {
        s->inUse[idx] = 1;
        s->unseqToSeq[idx] = (UChar)idx;
    }
    s->bsBuff = 0;
    s->bsLive = 0;
    s->blockCRC = 0;
    s->combinedCRC = 0;
    s->verbosity = 0;
    s->blockNo = 1;
    s->blockSize100k = 9;
    s->nMTF = 257;
    for (int idx = 0; idx < 258; idx++) {
        s->mtfFreq[idx] = 1;
        for (int tbl = 0; tbl < 6; tbl++) {
            s->len[tbl][idx] = 2;
            s->code[tbl][idx] = idx;
            s->rfreq[tbl][idx] = 1;
            for (int pack = 0; pack < 4; pack++) {
                s->len_pack[idx][pack] = 0;
            }
        }
    }
    for (int idx = 0; idx < 18002; idx++) {
        s->selector[idx] = 0;
        s->selectorMtf[idx] = 0;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct BswapDSPContext {
    void (*bswap_buf)(uint32_t *, const uint32_t *, int);
    void (*bswap16_buf)(uint16_t *, const uint16_t *, int);
} BswapDSPContext;

typedef struct MPADSPContext {
    void (*apply_window_float)(float *, float *, int *, float *, ptrdiff_t);
    void (*apply_window_fixed)(int32_t *, int32_t *, int *, int16_t *, ptrdiff_t);
    void (*dct32_float)(float *, const float *);
    void (*dct32_fixed)(int *, const int *);
    void (*imdct36_blocks_float)(float *, float *, float *, int, int, int);
    void (*imdct36_blocks_fixed)(int *, int *, int *, int, int, int);
} MPADSPContext;

typedef struct Band {
    int msf;
    int res[2];
    int scfi[2];
    int scf_idx[2][3];
    int Q[2];
} Band;

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef int32_t MPA_INT;

typedef struct MPCContext {
    BswapDSPContext bdsp;
    MPADSPContext mpadsp;
    int IS;
    int MSS;
    int gapless;
    int lastframelen;
    int maxbands;
    int last_max_band;
    int last_bits_used;
    int oldDSCF[2][32];
    Band bands[32];
    int Q[2][1152];
    int cur_frame;
    int frames;
    uint8_t *bits;
    int buf_size;
    AVLFG rnd;
    int frames_to_skip;
    MPA_INT synth_buf[2][1024] __attribute__((aligned(16)));
    int synth_buf_offset[2];
    int32_t sb_samples[2][36][32] __attribute__((aligned(16)));
} MPCContext;

MPCContext *c;
int i;
Band *bands;
int maxband;

void init_vars() {
    c = (MPCContext*)aligned_alloc(16, sizeof(MPCContext));
    if (!c) exit(1);

    memset(c, 0, sizeof(MPCContext));

    c->maxbands = 256;

    bands = (Band*)calloc(c->maxbands, sizeof(Band));
    if (!bands) exit(1);

    for (int j = 0; j < c->maxbands; j++) {
        bands[j].res[0] = rand();
        bands[j].res[1] = rand();
    }

    maxband = 128;
}

__attribute__((constructor)) void setup() {
    init_vars();
}